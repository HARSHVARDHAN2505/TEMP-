
#define BLYNK_TEMPLATE_ID "TMPL3gyX1_FwI"
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor"
#define BLYNK_AUTH_TOKEN "0vAvJ6rWdt2Uk-I-QhzYz-w9TlmG9ZqM"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 // Data pin is connected to D2 on 
#define DHTTYPE DHT11 // name the sensor as an object



char auth[] = "0vAvJ6rWdt2Uk-I-QhzYz-w9TlmG9ZqM";
char ssid[] = "HARSH";
char pass[] = "sweet dreams";

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Connected Successful");
  dht.begin();
}
// t.ly/netnex
void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();  // h= humidity
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intented");
    return; // 
  }
  Serial.println("Humidity: ");
  Serial.print(h);
  Serial.print("%");
  Serial.println("Temerature:");
  Serial.print(t);
  Serial.print(" degree celsius");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(1000);
}
