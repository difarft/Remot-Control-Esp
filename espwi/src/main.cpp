#include <Arduino.h>
#include <ESP8266WiFi.h>

//ssid and password, host name
const char* ssid     ="querily";
const char* password ="telkomseltino123";
String newHostname = "NodeMCU R";

//konfigurasi pin
const int input = A0;
const int servo = D5;
const int led1 = D6;
const int led2 = D7;
const int out1 = D1;
const int out2 = D2;

//variabel all


//fungsi wifi
void wifihdc(){
  //inisial wifi di router
  Serial.printf("Default hostname: %s\n", WiFi.hostname().c_str());
  WiFi.hostname(newHostname.c_str());
  Serial.printf("New hostname: %s\n", WiFi.hostname().c_str());

  //connet to wifi
  Serial.println("Mengubungkan ke ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  //menunggu terhubung
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("><....><");
    digitalWrite(led1, HIGH);
    delay(500);
  }

  //terhubung ke wifi
  Serial.println("Terhubung ke ");
  Serial.println(ssid);
  Serial.println("IP : ");
  Serial.println(WiFi.localIP());

  //reconnet to wifi
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
}


void setup() {
  //definisi input output pin
  pinMode(servo, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(input, INPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);

  digitalWrite(servo, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);  

  //panggil WiFi
  Serial.begin(115200);
  wifihdc();
  Serial.println("RSSI");
  Serial.println(WiFi.RSSI());
}

void loop() {
  
}

