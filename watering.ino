#define soil_moisture A0 // soil moisture sensor data pin #define Valvepin 5 //valve data pin
// variables defining
int val;
float moisture = 0.0; // variables defining void setup()
{
    Serial.begin(9600); // send data at port 9600 pinMode(soil_moisture, INPUT); //start soil moisture sensor
    pinMode(Valvepin, OUTPUT);
    void loop()
    {
        delay(1500);
        Serial.println("Reading Data");
        delay(1000);
        moisture = analogRead(soil_moisture); // getting soil moisture moisture = (moisture/1023)*100;
        if (isnan(moisture))                  // Adding failsafe for NaN values {
            Serial.println("Failed to read from soil misture sensor!");
    }
    return;
}
else
{
    Serial.print("Soil mositure: ");
    Serial.print(moisture);
    Serial.println(" %");
}
// printing soil moisture //printing soil moisture
// printing soil moisture
delay(1000);
if (moisture >= 40) // condition for motor to start {
    digitalWrite(Valvepin, HIGH);
Serial.println("Valve open");
}
else
{
    digitalWrite(Valvepin, LOW);
    Serial.println("Valve closed");
}
delay(1000);
Serial.println("\n");