/*
tutorial web server
https://www.youtube.com/watch?v=YEmfV74BPMI&list=PLYsqZkByVGHq9pRWmEWHALyWLKG1agmU1&index=6

*/
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Kantor Kel. Sumbang"; // Nama SSID AP/Hotspot
const char *password = "32mertoyudho";    // Password Wifi

ESP8266WebServer server(80); // Menyatakan Webserver pada port 80

void setup()
{
  Serial.begin(115200);
  delay(10);

  // Connect to WiFi network ------------------------------------------------
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Mengatur WiFi ----------------------------------------------------------
  WiFi.mode(WIFI_STA);        // Mode Station
  WiFi.begin(ssid, password); // Mencocokan SSID dan Password

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  // Print status Connect ---------------------------------------------------
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Membuat tampilan Webpage -----------------------------------------------
  server.on("/", []()
            { server.send(200, "text/plain", "Hello Para Warrior IoT"); });

  // Bagian ini opsional jika ingin membuat page lain ----------------------
  server.on("/status", []()
            { server.send(200, "text/plain", "Ini adalah Page Status Aktif"); });

  server.begin();
  Serial.println("Webserver dijalankan");
}

void loop()
{
  server.handleClient();
}