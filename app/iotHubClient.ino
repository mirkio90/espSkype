static WiFiClientSecure sslClient; // for ESP8266

const char *onSuccess = "\"Successfully invoke device method\"";
const char *notFound = "\"No method found\"";

static void sendCallback(IOTHUB_CLIENT_CONFIRMATION_RESULT result, void *userContextCallback)
{
    if (IOTHUB_CLIENT_CONFIRMATION_OK == result)
    {
        Serial.println("Message sent to Azure IoT Hub");
        //blinkLED();
    }
    else
    {
        Serial.println("Failed to send message to Azure IoT Hub");
    }
    messagePending = false;
}

//wip
static void sendMessage(IOTHUB_CLIENT_LL_HANDLE iotHubClientHandle, char *buffer, bool temperatureAlert)
{
    IOTHUB_MESSAGE_HANDLE messageHandle = IoTHubMessage_CreateFromByteArray((const unsigned char *)buffer, strlen(buffer));
    if (messageHandle == NULL)
    {
        Serial.println("Unable to create a new IoTHubMessage.");
    }
    else
    {
        MAP_HANDLE properties = IoTHubMessage_Properties(messageHandle);
        //Map_Add(properties, "temperatureAlert", temperatureAlert ? "true" : "false");
        Serial.printf("Sending message: %s.\r\n", buffer);
        if (IoTHubClient_LL_SendEventAsync(iotHubClientHandle, messageHandle, sendCallback, NULL) != IOTHUB_CLIENT_OK)
        {
            Serial.println("Failed to hand over the message to IoTHubClient.");
        }
        else
        {
            messagePending = true;
            Serial.println("IoTHubClient accepted the message for delivery.");
        }

        IoTHubMessage_Destroy(messageHandle);
    }
}

void green() {
  for(int i = 0; i < 12; i++){
    strip.SetPixelColor(i, hslGreen);
  }
  strip.Show();
}

void red() {
  for(int i = 0; i < 12; i++){
    strip.SetPixelColor(i, hslRed);
  }
  
  strip.Show();
}

void purple() {
  for(int i = 0; i < 12; i++){
    strip.SetPixelColor(i, hslPurple);
  }
 
  strip.Show();
}

void yellow() {
  for(int i = 0; i < 12; i++){
    strip.SetPixelColor(i, hslYellow);
  }
 
  strip.Show();
}

void personalColor(int R, int G, int B) {
  RgbColor personal(R, G, B);
  HslColor hslPersonal(personal);
  
  for(int i = 0; i < 12; i++){
    strip.SetPixelColor(i, hslPersonal);
  }
 
  strip.Show();
}

void redfadeinacall() {
  strip.SetPixelColor(0, hslRed);
  strip.SetPixelColor(1, hslRed);
  strip.SetPixelColor(2, hslRed);
  strip.SetPixelColor(3, hslRed);
  strip.SetPixelColor(4, hslRed);
  strip.SetPixelColor(5, hslRed);
  strip.SetPixelColor(6, hslWhite);
  strip.SetPixelColor(7, hslWhite);
  strip.SetPixelColor(8, hslWhite);
  strip.SetPixelColor(9, hslWhite);
  strip.SetPixelColor(10, hslWhite);
  strip.SetPixelColor(11, hslWhite);
  
  strip.Show();
}

void blueincomingcall() {
   for(int i = 0; i < 12; i++){
    strip.SetPixelColor(i, hslBlue);  
  }
  
  strip.Show();
}

void black() {
  for(int i = 0; i < 12; i++){
    strip.SetPixelColor(i, hslBlack);  
  }
   
  strip.Show();
}


IOTHUBMESSAGE_DISPOSITION_RESULT receiveMessageCallback(IOTHUB_MESSAGE_HANDLE message, void *userContextCallback)
{
    IOTHUBMESSAGE_DISPOSITION_RESULT result;
    const unsigned char *buffer;
    size_t size;
    if (IoTHubMessage_GetByteArray(message, &buffer, &size) != IOTHUB_MESSAGE_OK)
    {
        Serial.println("Unable to IoTHubMessage_GetByteArray.");
        result = IOTHUBMESSAGE_REJECTED;
    }
    else
    {
        /*buffer is not zero terminated*/
        char *temp = (char *)malloc(size + 1);

        if (temp == NULL)
        {
            return IOTHUBMESSAGE_ABANDONED;
        }

        strncpy(temp, (const char *)buffer, size);
        temp[size] = '\0';
        Serial.printf("Receive C2D message: %s.\r\n", temp);
        free(temp);
//        blinkLED();
    }
    return IOTHUBMESSAGE_ACCEPTED;
}



void twinCallback(
    DEVICE_TWIN_UPDATE_STATE updateState,
    const unsigned char *payLoad,
    size_t size,
    void *userContextCallback)
{
    char *temp = (char *)malloc(size + 1);
    for (int i = 0; i < size; i++)
    {
        temp[i] = (char)(payLoad[i]);
    }
    temp[size] = '\0';
    parseTwinMessage(temp);
    free(temp);
}
