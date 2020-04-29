#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "210984757244404ba04e82586129ddc8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "www.interactiverobotics.club";
char pass[] = "cilibur2019";

BlynkTimer timer;

void kirimdata()
{
  float suhu=random(27,35);
  float kelembaban=random(70,85);
  
  Blynk.virtualWrite(V0, suhu);
  Blynk.virtualWrite(V1, kelembaban);
  Blynk.virtualWrite(V2, "@iwan cilibur");
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "iwancilibur.ip-dynamic.com", 8080);
  timer.setInterval(1000L, kirimdata);
 }

void loop()
{
  Blynk.run();
  timer.run();
}
