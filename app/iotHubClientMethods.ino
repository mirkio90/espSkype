int deviceMethodCallback(
    const char *methodName,
    const unsigned char *payload,
    size_t size,
    unsigned char **response,
    size_t *response_size,
    void *userContextCallback)
{
    Serial.printf("Try to invoke method %s.\r\n", methodName);
    const char *responseMessage = onSuccess;
    int result = 200;

    if (strcmp(methodName, "green") == 0)
    {
        green();
    }
    else if (strcmp(methodName, "red") == 0)
    {
        red();
    }
    else if (strcmp(methodName, "purple") == 0)
    {
        purple();
    }
    else if (strcmp(methodName, "redfadeinacall") == 0)
    {
        redfadeinacall();
    }
    else if (strcmp(methodName, "blueincomingcall") == 0)
    {
        blueincomingcall();
    }
    else if (strcmp(methodName, "yellow") == 0)
    {
        yellow();
    }
    
    else
    {
        Serial.printf("No method %s found.\r\n", methodName);
        responseMessage = notFound;
        result = 404;
    }

    *response_size = strlen(responseMessage);
    *response = (unsigned char *)malloc(*response_size);
    strncpy((char *)(*response), responseMessage, *response_size);

    return result;
}
