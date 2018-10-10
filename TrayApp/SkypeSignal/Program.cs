using System;
using System.Windows.Forms;
using System.Threading;
using SkypeSignal.Interfaces;
using SkypeSignal.Helper;

namespace SkypeSignal
{
    internal static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {      

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            //I've found that my Arduino hangs on the very first connection to work around that
            //kick-off connection to Light before we start and send a non-event code:
            ISender serialSender = Helpers.SenderFabricator();
            serialSender.SendData("0");
            
            var skypeStatus = new SkypeStatusInfo();

            var skypeStatusMonitor = new Thread(skypeStatus.StatusSetup);
            


            skypeStatusMonitor.Start();  
            
            //Show the System Tray Icon
            using (ProcessIcon pi = new ProcessIcon())
            {
                pi.DisplayIcon();

                //Make Sure the Application Runs
                Application.Run();
            }           
        }
    }
}
