#define BLYNK_TEMPLATE_ID "TMPL3LWJ6vXQd"
#define BLYNK_TEMPLATE_NAME "energy meter"
#define BLYNK_AUTH_TOKEN "7pd86JehzTEAkXFIu05uHMRLC3dvvd9I"
 
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#include "EmonLib.h" 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
 WiFiClient client;

char auth[] = BLYNK_AUTH_TOKEN; 
 
const char *ssid =  "Redmi123";     // replace with your wifi ssid and wpa2 key
const char *pass =  "123456780";
  
BlynkTimer timer; 
 
EnergyMonitor emon;
 
#define vCalibration 83.3
#define currCalibration 0.50

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
  
float kWh = 0;

unsigned long lastmillis = millis();
 
void myTimerEvent()
{
  emon.calcVI(20, 2000);
  kWh = kWh + emon.apparentPower * (millis() - lastmillis) / 3600000000.0;
  yield();
  Serial.print("Vrms: ");
  Serial.print(emon.Vrms, 2);
  Serial.print("V");
 
  Serial.print("\tIrms: ");
  Serial.print(emon.Irms, 4);
  Serial.print("A");
 
  Serial.print("\tPower: ");
  Serial.print(emon.apparentPower, 4);
  Serial.print("W");
 
  Serial.print("\tkWh: ");
  Serial.print(kWh, 5);
  Serial.println("kWh");
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vrms:");
  lcd.print(emon.Vrms, 2);
  lcd.print("V");
  lcd.setCursor(0, 1);
  lcd.print("Irms:");
  lcd.print(emon.Irms, 4);
  lcd.print("A");
  delay(2500);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Power:");
  lcd.print(emon.apparentPower, 4);
  lcd.print("W");
  lcd.setCursor(0, 1);
  lcd.print("kWh:");
  lcd.print(kWh, 4);
  lcd.print("W");
  delay(2500);
 
  lastmillis = millis();
 
  Blynk.virtualWrite(V0, emon.Vrms);
  Blynk.virtualWrite(V1, emon.Irms);
  Blynk.virtualWrite(V2, emon.apparentPower);
  Blynk.virtualWrite(V3, kWh);
}
 
void setup()
{
  Serial.begin(115200);
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
    lcd.begin();
  lcd.backlight();
 
  emon.voltage(35, vCalibration, 1.7); // Voltage: input pin, calibration, phase_shift
  emon.current(34, currCalibration); // Current: input pin, calibration.
 
  timer.setInterval(5000L, myTimerEvent);
  lcd.setCursor(3, 0);
  lcd.print("IoT Energy");
  lcd.setCursor(5, 1);
  lcd.print("Meter");
  delay(3000);
  lcd.clear();
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
