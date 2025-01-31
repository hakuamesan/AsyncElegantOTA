
<h1> Fork from Ayush Sharma's Async Elegant OTA</h1>

<p align="center"><img src="/docs/logo.svg?sanitize=true&raw=true" width="400"></p>

<hr/>
<p align="center">
<img src="https://img.shields.io/github/last-commit/hakuamesan/AsyncElegantOTA.svg?style=for-the-badge" />
&nbsp;
<img src="https://img.shields.io/github/actions/workflow/status/hakuamesan/AsyncElegantOTA/ci.yml?branch=master&style=for-the-badge" />
&nbsp;
<img src="https://img.shields.io/github/license/hakuamesan/AsyncElegantOTA.svg?style=for-the-badge" />
&nbsp;
</p>
<hr/>


<p align="center">Perform OTAs for ESP32 Asynchronously</p>
<p align="center">
AsyncElegantOTA provides a beautiful interface to upload Over the Air `.bin` updates to your ESP Modules with precise status and progress displayed over UI. This Library shows the current upload progress of your OTA and once finished, it will display the status of your OTA. This Version of Library uses AsyncWebServer. Thanks to @me-no-dev for a wonderful webserver library.
</p>

<p>
Removed code that was not useful to me so that it is more compact.
</p>

<br>
<br>

<h2 align="center">Preview</h2>
<p align="center"><img src="/docs/elegantOtaDemo.gif?raw=true"></p>

<br>
<br>

<h2>How to Install</h2>

###### Directly Through Arduino IDE ( Currently Submitted for Approval. Use Mannual Install till it gets Approved.)
Go to Sketch > Include Library > Library Manager > Search for "AsyncElegantOTA" > Install

###### Manual Install
For Linux: Download the [Repository](https://github.com/hakuamesan/AsyncElegantOTA/archive/master.zip) and extract the .zip in Sketchbook>Libraries>{Place "ElegantOTA" folder Here}

###### Manually through IDE

Download the [Repository](https://github.com/hakuamesan/AsyncElegantOTA/archive/master.zip), Go to Sketch>Include Library>Add .zip Library> Select the Downloaded .zip File.

<br>

<h2>Documentation</h2>
<p>AsyncElegantOTA is a dead simple library which does your work in just 1 Line. Honestly, It's just a wrapper library which injects it's own elegant webpage instead of the ugly upload page which comes by default in Arduino Library.</p>

 Include AsyncElegantOTA Library `#include <AsyncElegantOTA.h>` at top of your Arduino Code.
 
 Paste this - `AsyncElegantOTA.begin(&server);`  line above your `server.begin();`
 
 That's all!
 
 Now copy the IPAddress displayed over your Serial Monitor and go to `http://<IPAddress>/update` in browser. ( where `<IPAddress>` is the IP of your ESP Module)
 
 <br>
 
 #### Additional Security:
 
 If you would like to add login to your OTA webpage, then please replace `AsyncElegantOTA.begin(&server);` with `AsyncElegantOTA.begin(&server, "username", "password");`. This will prevent unauthorized requests to your OTA webpage and prevent unauthorized firmware upload to your MCU.
 
<br>

<b>Antivirus Issue:</b> If you have an antivirus on your PC with internet security, the progress bar on webpage will instantly show 100% because of request caching by your antivirus software. There is no fix for this unless you want to disable your antivirus or whitelist your local IP addresses in it. ( Same is the case with iOS, safari will cache the outgoing requests )

<br>

<h2>Tutorials</h2>
<p>Tutorials for AsyncElegantOTA is live on RandomNerdTutorials.</p>

<h3>ESP8266</h3> 
<h4>Arduino IDE:</h4>
<p>https://randomnerdtutorials.com/esp8266-nodemcu-ota-over-the-air-arduino/</p>
<h4>PlatformIO (manual method):</h4>
<p>https://randomnerdtutorials.com/esp8266-nodemcu-ota-over-the-air-vs-code/</p>
<br>

<h3>ESP32</h3>
<h4>Arduino IDE:</h4>
<p>https://randomnerdtutorials.com/esp32-ota-over-the-air-arduino/</p>
<h4>PlatformIO (manual method):</h4>
<p>https://randomnerdtutorials.com/esp32-ota-over-the-air-vs-code/</p>
<br>

<h3>PlatformIO Automatic Method</h3>
<ul>
<li> Copy the file "platformio_upload.py" from this repository into the same folder as your platformio.ini file
<li> Set the upload method for your project in platformio.ini:
</ul>

```
extra_scripts = platformio_upload.py
upload_protocol = custom
upload_url = <your upload URL, such as http://192.168.1.123/update>
``` 
<br>
<h2>Examples</h2>
 
<h3>For ESP32:</h3>

```
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>

const char* ssid = "........";
const char* password = "........";

AsyncWebServer server(80);


void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });

  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
}

```
<br>
<br>

<h2>Contributions</h2>
<p>Every Contribution to this repository is highly appriciated! Don't fear to create pull requests which enhance or fix the library as ultimatly you are going to help everybody.</p>
<p>

<br/>
<br/>


<h2>License</h2>
ESP-DASH is licensed under MIT.
<br/>
<br/>
<img src="https://img.shields.io/github/license/hakuamesan/AsyncElegantOTA.svg?style=for-the-badge" />
</div>
