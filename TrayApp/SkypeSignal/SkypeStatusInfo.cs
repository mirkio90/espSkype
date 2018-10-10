using System;
using System.Windows.Forms;
using System.Threading;
using System.Timers;
using Microsoft.Lync.Model;
using Microsoft.Lync.Model.Conversation;
using Microsoft.Lync.Model.Conversation.AudioVideo;
using SkypeSignal.Interfaces;
using SkypeSignal.Helper;

namespace SkypeSignal
{
    internal class SkypeStatusInfo
    {
        readonly ISender _sender = Helpers.SenderFabricator();
        private readonly System.Timers.Timer _partyTimer = new System.Timers.Timer();

        LyncClient _lyncClient;

        public SkypeStatusInfo()
        {
            _partyTimer.Enabled = true;
            _partyTimer.Interval = 20000;
            _partyTimer.AutoReset = false;
            _partyTimer.Elapsed += PartyTimerElapsed;
        }

        public void StatusSetup()
        {
            while (_lyncClient == null)
            {
                try
                {
                    _lyncClient = LyncClient.GetClient();
                }
                catch (Exception)
                {                    
                    MessageBox.Show("Cannot find a Lync client - Quitting", "Lync Client Process Not found", MessageBoxButtons.OK, MessageBoxIcon.Error);

                    //Quit - We cant do anything.
                    Environment.Exit(1);
                }

                if (_lyncClient != null && _lyncClient.State == ClientState.SignedIn)
                {
                    //Subscribe to Conversation Added events for Incoming call alerts:
                    _lyncClient.ConversationManager.ConversationAdded += ConversationAdded;

                    //Subscribe to Contact Information Changed events for client status changes.
                    _lyncClient.Self.Contact.ContactInformationChanged += ContactChangeStatusUpdate;
                }
            }
        }

        private void ContactChangeStatusUpdate(object sender, ContactInformationChangedEventArgs e)
        {
            if (e.ChangedContactInformation.Contains(ContactInformationType.ActivityId))
            {
                SetCurrentLyncStatus();
            }
        }

        private void ConversationAdded(object sender, ConversationManagerEventArgs e)
        {
            var notified = false;
            var avModality = (AVModality) e.Conversation.Modalities[ModalityTypes.AudioVideo];


            while (e.Conversation.Modalities[ModalityTypes.AudioVideo].State == ModalityState.Notified &&
                   e.Conversation.State == ConversationState.Active)
            {
                while (notified != true)
                {
                    //We have an incomming call
                    if (avModality.State == ModalityState.Notified)
                    {
                        _sender.SendData(ColourStates.BlueIncomingCall);

                        notified = true;
                    }
                }
            }
            //Return user back to their current Sykpe State     
            SetCurrentLyncStatus();
        }

        private void SetCurrentLyncStatus()
        {
            _lyncClient = LyncClient.GetClient();
            
            if (_lyncClient != null && _lyncClient.State == ClientState.SignedIn)
            {
                var status = _lyncClient.Self.Contact.GetContactInformation(ContactInformationType.ActivityId).ToString();

                switch (status)
                {
                    case "Free":
                        _sender.SendData(ColourStates.Green);
                        break;
                    case "in-a-meeting":
                    case "Busy":
                        _sender.SendData(ColourStates.Red);
                        break;
                    case "DoNotDisturb":
                    case "out-of-office":
                    case "urgent-interruptions-only":
                    case "presenting":
                        _sender.SendData(ColourStates.Purple);
                        break;
                    case "Away":
                    case "BeRightBack":
                    case "off-work":
                    case "Inactive":
                        _sender.SendData(ColourStates.Yellow);
                        break;
                    case "on-the-phone":
                    case "in-a-conference":
                        _sender.SendData(ColourStates.RedFadeInACall);
                        break;
                    default:
                        _sender.SendData(ColourStates.Off);
                        break;
                }
            }
            else _sender.SendData(ColourStates.Off);
        }

        
        public void PartyDown()
        {
            //Wimmy Wam Wam Wozzle!!!
            _sender.SendData(ColourStates.PartyStrobe);
            _partyTimer.Start();
        }

        private void PartyTimerElapsed(object source, ElapsedEventArgs e)
        {
            //Reset Light to current Lync status by forcing a Check.
            SetCurrentLyncStatus();
        }
    }
}
