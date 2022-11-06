

#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;

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
