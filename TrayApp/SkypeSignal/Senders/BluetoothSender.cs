using SkypeSignal.Interfaces;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using InTheHand.Net.Sockets;
using InTheHand.Devices.Bluetooth;
using InTheHand.Net.Bluetooth;

namespace SkypeSignal.Senders
{
    class BluetoothSender : ISender
    {
        static SerialPort _serialPort;

        private BluetoothDeviceInfo device;
        private BluetoothClient client;

        public BluetoothSender() {
            if (device == null)
            {
                client = new BluetoothClient();
                BluetoothDeviceInfo[] devices = client.DiscoverDevices();
                Guid serviceClass = BluetoothService.SerialPort;
                device = devices.Where(d => d.DeviceName.Equals(ConfigurationManager.AppSettings["DeviceName"])).FirstOrDefault();

                client.Connect(device.DeviceAddress, serviceClass);
            }
        }

        public void SendData(string Command)
        {
            if (device.Authenticated)
            {
                client.Client.Send(Encoding.ASCII.GetBytes(Command + ";"));
            }
        }

    }
}
