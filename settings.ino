#include <SPI.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#define sensor_pin A0 // soil moisture sensor data pin
#define valve_pin 5   // valve data pin
#include "ThingSpeak.h"
//#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
unsigned long myChannelNumber = 1400693; // plant1
// unsigned long myChannelNumber = 1400698; //plant2 //use these plant specific //unsigned long myChannelNumber = 1400700; //plant3
// unsigned long myChannelNumber = 1400701; //plant4
const char *apiKey = "450O1IDRLQ7BFMK4"; // API key for plant1
// const char * apiKey = "TLY7G725N8C8Q7PJ"; // API key for plant2 //use these plant specific
// const char * apiKey = "P993SGRIXKLP4GFF"; // API key for plant3
// const char * apiKey = "GZ0NE1GN4E22T7A2"; // API key for plant4
const char *ssid = "Alexahome"; // replace with your wifi ssid and wpa2 key @srish const char *pass = "12345678";
const char *server = "api.thingspeak.com";
// const int sensor_pin = A0; // Connect Soil moisture analog sensor pin to A0 of NodeMCU //const int valve_pin = 5;
WiFiClient client;
void setup()
{
    Serial.begin(115200);
    // display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C
    (128x64)

        // display.clearDisplay(); delay(10);
        pinMode(sensor_pin, INPUT);
    pinMode(valve_pin, OUTPUT);
    WiFi.mode(WIFI_STA);
    ThingSpeak.begin(client);
}
void loop()
{
    // int moisture_percentage; float moisture;
    moisture = analogRead(sensor_pin);
    moisture = (moisture / 1023) * 100;
    // moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
    Serial.print("Soil Moisture(in Percentage) = ");
    Serial.print(moisture);
    Serial.println("%");
    if (moisture <= 40) // condition for motor to start {
        digitalWrite(valve_pin, HIGH);
    Serial.println("Valve open");
}
else
{
    digitalWrite(valve_pin, LOW);
    Serial.println("Valve closed");
}

// char valve_status = digitalRead(valve_pin);
if (WiFi.status() != WL_CONNECTED)
{
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
        WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
        Serial.print(".");
        delay(2000);
    }
    Serial.println("\nConnected.");
}
// Write value to Field 1 of a ThingSpeak Channel
int httpCode = ThingSpeak.writeField(myChannelNumber, 1, moisture, apiKey);
// int httpCode1 = ThingSpeak.writeField(myChannelNumber, 2, valve_status, apiKey);
if (httpCode == 200)
{
    Serial.println("Channel write successful.");
}
else
{
    Serial.println("Problem writing to channel. HTTP error code " + String(httpCode));
}
}