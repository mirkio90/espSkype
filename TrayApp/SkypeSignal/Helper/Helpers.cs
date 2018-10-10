using SkypeSignal.Interfaces;
using SkypeSignal.Senders;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SkypeSignal.Helper
{
    public static class Helpers
    {
        public static ISender SenderFabricator() {
            string actualConfig = ConfigurationManager.AppSettings["SenderType"].ToUpper();

            switch (actualConfig)
            {
                case "HUB":
                    return new HubSender();
                case "SERIAL":
                    return new SerialSender();
                case "BLUETOOTH":
                    return new BluetoothSender();
                default:
                    throw new ConfigurationErrorsException("Sender Configuration not found");
            }
        }
    }
}
