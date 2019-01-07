#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#include "BluetoothSerial.h"
#include "config.h"

#include <time.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
CRGB leds[LED_NUMBER];
String message; //Message buffer
char character; 



void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, LED_NUMBER);
}

void loop() {
  String old = "";
  //roll_pitch();
  if(SerialBT.available()){
    character = SerialBT.read();
    Serial.print(character);
    message.concat(character);
    if(character == ';'){
      int messageLength = message.length();
      char messageChar[messageLength] = "";
      message.toCharArray(messageChar, messageLength);
      Serial.println("\n invoking method: ");
      Serial.print(messageChar);
      invokeColor(messageChar);

//      for( int i = 0; i < sizeof(messageChar);  ++i ){
//        Serial.println(messageChar[i]);
//        messageChar[i] = '';
//      }
      message = "";
      messageChar[0] = 0;
    }
  }

//  
//  int messageLength = message.length();
//  char messageChar[messageLength] = "";

//  message.toCharArray(messageChar, messageLength);
//  invokeColor(messageChar);
  delay(20);
}
