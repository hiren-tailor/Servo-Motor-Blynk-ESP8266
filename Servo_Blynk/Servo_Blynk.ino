#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>


char auth[] = "7DULAhnX27lwf0wnHrOaUtW_u__lsnQ_";
char ssid[] = "Hiren";
char pass[] = "123456789";

Servo servo;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,"188.166.206.43",80);  //PING blynk-cloud.com
  //Blynk.begin(auth, ssid, pass);
  servo.attach(5); // NodeMCU D1 pin (GPIO-5)
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V1)
{
   servo.write(param.asInt());
}
