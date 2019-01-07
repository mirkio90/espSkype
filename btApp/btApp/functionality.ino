void invokeColor(char methodName[])
{
    Serial.printf("\nTry to invoke method %s.\r\n", methodName);

    char color[] = "green";
  
    if (strcmp(methodName, "1") == 0)
    {
        Serial.println("green called");
        green();
    }
    else if (strcmp(methodName, "2") == 0)
    {
        Serial.println("red called");
        red();
    }
    else if (strcmp(methodName, "3") == 0)
    {
        purple();
    }
//    else if (strcmp(methodName, "redfadeinacall") == 0)
//    {
//        redfadeinacall();
//    }
//    else if (strcmp(methodName, "blueincomingcall") == 0)
//    {
//        blueincomingcall();
//    }
    else if (strcmp(methodName, "4") == 0)
    {
        yellow();
    }
//    
    else if (strcmp(methodName, "0") == 0)
    {
        off();
    }
    else
    {
        Serial.printf("No method %s found.\r\n", methodName);
    }
}

String roll_pitch(){ //
  while(SerialBT.available()){
    character = SerialBT.read();
    Serial.print(character);
    message.concat(character);
    if(character == '#'){ // if end of message received
      break;
    }  
  }
  Serial.println(message);
}
