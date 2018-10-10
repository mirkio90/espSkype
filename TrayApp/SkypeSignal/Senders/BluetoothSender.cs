using SkypeSignal.Interfaces;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SkypeSignal.Senders
{
    class BluetoothSender : ISender
    {
        static SerialPort _serialPort;

        public void SendData(string Command)
        {
            _serialPort = new SerialPort();

            _serialPort.BaudRate = getSerialBaudRate();
            _serialPort.PortName = getPortName(); // Set in Windows
            _serialPort.Open();

            using (_serialPort)
            {
                _serialPort.WriteLine(Command);
            }
        }

        private int getSerialBaudRate()
        {
            int baudrate;

            if (!int.TryParse(ConfigurationManager.AppSettings["BaudRate"], out baudrate))
            {
                baudrate = 9600;
            }

            return baudrate;
        }

        private string getPortName()
        {
            string portName;
            portName = "COM4";

            if (!string.IsNullOrEmpty(ConfigurationManager.AppSettings["PortName"]))
            {
                portName = ConfigurationManager.AppSettings["PortName"];
            }

            return portName;
        }
    }
}
