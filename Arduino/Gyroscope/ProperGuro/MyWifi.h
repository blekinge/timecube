

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>



WiFiMulti wifiMulti;



struct header_t {
  const String name;
  const String value;
};


struct endpoint_t {
  const char* httpMethod;
  String url;
  String body;
  header_t headers[4];
  uint8_t count;
  String username;
  String password;
  String authMethod;
};




//void setupWifi(const char* ssid, const char* password)
void setupWifi(const char* ssid, const char* password)
{

  WiFi.mode(WIFI_STA);

  wifiMulti.addAP(ssid, password);

  //  wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
    Serial.println("no networks found");
  }
  else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println();
      delay(10);
    }
  }

  Serial.println("Connecting Wifi...");
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("Wi-Fi CONNECTED!");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }

}


String getRequest(endpoint_t endpoint)
{

  //https://github.com/espressif/arduino-esp32/blob/master/libraries/HTTPClient/src/HTTPClient.h
  HTTPClient http;

  // configure traged server and url
  //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
  http.begin(endpoint.url); //HTTP

  // start connection and send HTTP header
  int httpCode = http.sendRequest(endpoint.httpMethod,endpoint.body);

  String result = http.getString();

  http.end();

  return result;

}
