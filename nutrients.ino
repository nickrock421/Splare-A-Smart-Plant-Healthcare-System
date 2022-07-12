#define soil_moisture A1      // soil moisture sensor data pin
#define pressure A0           // pressure sensor data pin
#define kpa2atm 0.00986923267 // conversion factor bet'n kpa to atm #include "DHT.h" //include DHT library
#define DHTPIN 6              // DHT sensor data pin
#define DHTTYPE DHT11         // include DHT type
#define PHPIN 2
#define NPIN A2
#define PPIN A3
#define KPIN A4
#define Valvepin A5
// variables defining
int val; // variables defining float pkPa; // pressure in kPa float pAtm; // pressure in Atm
// PH sensor data pin //Nitrogen data pin //Phosporous data pin //Potassium data pin //valve data pin
DHT dht(DHTPIN, DHTTYPE); // define DHT function
void setup()
{
    Serial.begin(9600);            // send data at port 9600 dht.begin(); //start DHT
    pinMode(soil_moisture, INPUT); // start soil moisture sensor
    pinMode(PHPIN, INPUT);
    pinMode(NPIN, INPUT);
    pinMode(PPIN, INPUT);
    pinMode(KPIN, INPUT);
    pinMode(Valvepin, OUTPUT);
}
void loop()
    // start pH sensor //start N sensor //start P sensor //start K sensor //valve pin
{
    delay(3000);
    Serial.println("--Reading Data--");
    Serial.println();
    delay(100);
    float moisture = analogRead(soil_moisture); // getting soil moisture moisture = (moisture/1023)*100; //getting soil moisture
    if (isnan(moisture))                        // Adding failsafe for NaN values {
        Serial.println("**Failed to read from soil misture sensor!**");
    return;
}
else
{
    Serial.print("Soil mositure: ");
    Serial.print(moisture);
    Serial.println(" %");
}
delay(100);
val = analogRead(pressure);
pkPa = ((float)val / (float)1023 + 0.095) / 0.009; // getting pressure pAtm = kpa2atm*pkPa; //getting pressure
if (isnan(pressure))                               // Adding failsafe for NaN values {
    Serial.println("**Failed to read from pressure sensor!**");
return;
}
else
{
    Serial.print("Pressure in kPa: ");
    Serial.println(pkPa);
    Serial.print("Pressure in Atm: ");
    Serial.println(pAtm);
}
// printing pressure //printing pressure
// printing pressure //printing pressure
delay(100);
float Relative_Humidity = dht.readHumidity();       // Read the humidity
float Absolute_Temperature = dht.readTemperature(); // Read the temperature
if (isnan(Relative_Humidity) || isnan(Absolute_Temperature))
    NaN values
    {
        Serial.println("**Failed to read from DHT sensor!**");
        return;
    }
else
{
    Serial.print("Humidity: "); // print H and T Serial.println(Relative_Humidity*10); //print H and T Serial.print("\tTemperature: "); //print H and T Serial.println(Absolute_Temperature*10);} //print H and T
    delay(100);
    float pH_value = analogRead(PHPIN); // read pH value
    if (isnan(pH_value))                // Adding failsafe for NaN values {
        Serial.println("**Failed to read from pH sensor!**");
    return;
}
else
{
    Serial.print("pH level is: "); // print pH value Serial.println(pH_value/71.43);} //print pH value
    delay(100);
    float n_value = analogRead(NPIN); // getting N value float p_value = analogRead(PPIN); //getting P value float k_value = analogRead(KPIN); //getting K value
    // Adding failsafe for

    if (isnan(n_value) || isnan(p_value) || isnan(k_value)) // Adding failsafe for NaN values
    {
        Serial.println("**Failed to read from NPK sensor!**");
        return;
    }
    else
    {
        delay(100);
        Serial.print("N VALUE (ppm): ");
        Serial.println(n_value / 28.57);
        delay(100);
        Serial.print("P VALUE (ppm): ");
        Serial.println(p_value / 40); // printing P value
        delay(100);
        Serial.print("K VALUE (ppm): "); // printing K value Serial.println(k_value/20); } //printing K value Serial.println();
        Serial.println("--Task being performed--");
        Serial.println();
        if (moisture <= 40)               // condition for motor to start {
            digitalWrite(Valvepin, HIGH); // condition for motor to start
        Serial.println("--> Watering (Valve is open)");
    }
    else
    {
        Serial.println("--> No need to water plants (Valve is closed)");
    }
    Serial.println();
    Serial.println("--Task to be performed--");
    Serial.println();
    // printing N value //printing N value
    // printing P value
    digitalWrite(Valvepin, LOW); // condition for motor to stop

    if (pH_value / 71.43 >= 6 && pH_value / 71.43 <= 7)
    {
        Serial.println("--> pH of soil is normal");
    }
    else if (pH_value / 71.43 < 6)
    {
        Serial.println("--> pH of soil is very low. Please add limestone in soil");
    }
    else
    {
        Serial.println("--> pH of soil is very high. Please add aluminium sulphate in soil");
    }
    if (Absolute_Temperature * 10 <= 30)
    {
        Serial.println("--> Teamperature is normal no need of worry");
    }
    else
    {
        Serial.println("--> Tempearture is high. Please place plants in shadow");
    }
    if (n_value / 28.57 >= 40 && n_value / 28.57 <= 60)
    {
        Serial.println("--> Nitrogen amount in soil is normal");
    }
    else if (n_value / 28.57 < 40)
    {
        Serial.println("--> Nitrogen amount in soil is very low. Please add urea in soil");
    }
    else
    {
        Serial.println("--> Nitrogen of soil is very high. Please add dyed mulch in soil");
    }
    if (p_value / 40 >= 4 && p_value / 40 <= 6)
    {
        Serial.println("--> Phosphorus amount in soil is normal");
    }
    else if (p_value / 40 < 4)
    {
        Serial.println("--> Phosphorus amount in soil is very low. Please add organic matter in soil");
    }
    else
    {
        Serial.println("--> Phosphorus of soil is very high. Please add dyed mulch in soil");
    }
    if (k_value / 20 >= 170 && k_value / 20 <= 190)
    {
        Serial.println("--> Potassium amount in soil is normal");
    }
    else if (k_value / 20 < 170)
    {
        Serial.println("--> Potassium amount in soil is very low. Please add food byproducts in soil");
    }
    else
    {
        Serial.println("--> Potassium of soil is very high. Please add dyed mulch in soil");
    }
    delay(1000);
    Serial.println();
    Serial.println();
    Serial.println();
}