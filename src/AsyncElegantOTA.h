#ifndef AsyncElegantOTA_h
#define AsyncElegantOTA_h

#include <Arduino.h>
#include <stdlib_noniso.h>
#include <WiFi.h>
#include "AsyncTCP.h"
#include "Update.h"
#include "esp_int_wdt.h"
#include "esp_task_wdt.h"
#include "Hash.h"
#include "ESPAsyncWebServer.h"
#include "FS.h"
#include "elegantWebpage.h"


class AsyncElegantOtaClass{

    public:
        void
            setID(const char* id),
            begin(AsyncWebServer *server, const char* username = "", const char* password = ""),
            loop(),
            restart();

    private:
        AsyncWebServer *_server;

        String getID();

        String _id = getID();
        String _username = "";
        String _password = "";
        bool _authRequired = false;

};

extern AsyncElegantOtaClass AsyncElegantOTA;

#endif
