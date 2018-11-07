#include <Stepper.h>

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiUdp.h>

#include <AzureIoTHub.h>
#include <AzureIoTProtocol_MQTT.h>
#include <AzureIoTUtility.h>

#include <NeoPixelBus.h>
#include <time.h>

extern "C" {
  #include "user_interface.h"
  #include "wpa2_enterprise.h"
}

#include "config.h"

#define colorSaturation 128

const uint16_t PixelCount = 12; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 2;  // make sure to set this to the correct pin, ignored for Esp8266

static bool messagePending = false;
static bool messageSending = true;

static char *connectionString = "HostName=iothubmirkio.azure-devices.net;DeviceId=esp;SharedAccessKey=/pK+kwavQEJ4s6hewLEWa/rNL7YaDJi1YW3jC8uYQks=";
static char* ssid = "wifi-access";
static char* username = "mirko.a.usai";
static char* pass = "***";

char wlpasswd[] = "***";

static int interval = INTERVAL;
static IOTHUB_CLIENT_LL_HANDLE iotHubClientHandle;
static int messageCount = 1;
int timezone = 1;

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

//color definition
RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);

void setup() {
  // put your setup code here, to run once:
  initSerial();
  delay(2000);

  strip.Begin();
  strip.Show();
  
  setCommonWifi();
  //initWifiPeap();
  initTime();

   //initIoThubClient();

  iotHubClientHandle = IoTHubClient_LL_CreateFromConnectionString(connectionString, MQTT_Protocol);
  
  while(iotHubClientHandle == NULL) {
    iotHubClientHandle = IoTHubClient_LL_CreateFromConnectionString(connectionString, MQTT_Protocol);
    Serial.println("Failed on IoTHubClient_CreateFromConnectionString.");
 }

  IoTHubClient_LL_SetMessageCallback(iotHubClientHandle, receiveMessageCallback, NULL);
  IoTHubClient_LL_SetDeviceMethodCallback(iotHubClientHandle, deviceMethodCallback, NULL);
  IoTHubClient_LL_SetDeviceTwinCallback(iotHubClientHandle, twinCallback, NULL);

}

void loop() {
    if (!messagePending && messageSending)
    {
//        char messagePayload[MESSAGE_MAX_LEN];
//        bool temperatureAlert = readMessage(messageCount, messagePayload);
//        sendMessage(iotHubClientHandle, messagePayload, temperatureAlert);
//        messageCount++;
//        delay(interval);
    }
    IoTHubClient_LL_DoWork(iotHubClientHandle);
//    delay(10);
}

void initSerial(){
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    Serial.println("Serial successfully inited.");
}

void initWifiPeap() {
  wifi_set_opmode(0x01);
  WiFi.mode(WIFI_STA);
  Serial.printf("Attempting to connect to SSID: %s.\r\n", ssid);
  struct station_config wifi_config;

  memset(&wifi_config, 0, sizeof(wifi_config));
  strcpy((char*)wifi_config.ssid, ssid);

  wifi_station_set_config(&wifi_config);

  wifi_station_clear_cert_key();
  wifi_station_clear_enterprise_ca_cert();

  wifi_station_set_wpa2_enterprise_auth(1);
  wifi_station_set_enterprise_username((uint8*)username, strlen(username));
  wifi_station_set_enterprise_password((uint8*)pass, strlen(pass));

  WiFi.begin(ssid, wlpasswd);
  
  wifi_station_connect();
  Serial.print("Wifi station connect status:");
  Serial.println(wifi_station_get_connect_status());

  // Wait for connection AND IP address from DHCP
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(WiFi.status());
    delay(2000);
    Serial.println("Not connected");
  }
  
  WiFi.begin(ssid, wlpasswd);
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP() + "\n");

  Serial.println("try to obtain ip...");
  
  while((String)WiFi.localIP() == "")
  {
      Serial.print(".");
      delay(500);
  }
  Serial.println(WiFi.localIP());
  WiFi.printDiag(Serial);  
}

void setCommonWifi(){
  WiFi.begin("Infostrada-953F21", pass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void initTime(){
    time_t epochTime;
    configTime(timezone * 3600, 0, "pool.ntp.org");

    int i = 0;
    
    while (i < 10) {
      Serial.print(".");
      i++;
      delay(1000);
    }
    i = 0;
    while (true)
    {
        epochTime = time(nullptr);

        if (epochTime < 30000 && i < 15)
        {
            i++;
            Serial.println("Fetching NTP epoch time failed! Waiting 5 seconds to retry.");
            delay(5000);
        }
        else if (epochTime < 30000 && i >= 15) {
            Serial.print("insert time value");
            Serial.read();
        }
        else
        {
            Serial.printf("Fetched NTP epoch time is: %lu.\r\n", epochTime);
            time_t tnow = time(nullptr);
            Serial.print(String(ctime(&tnow)));
            break;
        }
    }
}
