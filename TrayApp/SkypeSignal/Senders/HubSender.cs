using SkypeSignal.Interfaces;
using System;
using System.Threading.Tasks;
using Microsoft.Azure.Devices;
using System.Configuration;

namespace SkypeSignal
{
    class HubSender : ISender
    {
        public void SendData(string Command)
        {
            Task test = Run(ColourStates.GetNameFromCode(Command).ToLower());
            test.Wait();
        }

        private async Task Run(string input)
        {
            var connectionString = ConfigurationManager.AppSettings["ConnectionString"];
            var serviceClient = ServiceClient.CreateFromConnectionString(connectionString);

            var cloudToDeviceMethod = new CloudToDeviceMethod(input);

            var response = await serviceClient.InvokeDeviceMethodAsync("esp", cloudToDeviceMethod);

            var json = response.GetPayloadAsJson();
        }
    }
}
