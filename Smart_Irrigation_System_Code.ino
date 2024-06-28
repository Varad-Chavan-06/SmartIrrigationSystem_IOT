#include <DHT11.h>

#include <LiquidCrystal.h>
#include <DHT11.h>

LiquidCrystal lcd(7,6,5,4,3,2);
const int relay_Pin = 8;
//const int DHT11_Sesnor = 9;
const int moisture_sensor = A0;
const int rain_Sesnor = A1;

#define DHTTYPE DHT11
int  moisture_sensor_value;
int rain_Sesnor_value;
float humudity_value,temprature_value;
DHT11 dht11(12);

void setup() {
  Serial.begin(9600);  
  pinMode(relay_Pin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Smart Irrigation ");
  lcd.setCursor(0,2);
  lcd.print(" SYSTEM");
  digitalWrite(relay_Pin, LOW); 
  //dht11.begin();
   delay(2000);
}
void loop() 
{

  moisture_level_detected();
  water_motor_start();
}


/*void readDTH11_Sesnor()
{

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  humudity_value = dht11.readHumidity();
  // Read temperature as Celsius (the default)
  temprature_value = dht11.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humudity_value) || isnan(temprature_value)) {
    Serial.println(("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print((" Humidity: "));
  Serial.print(humudity_value);
  Serial.print(("%"));
  lcd.clear();
  lcd.print("Humidity %: ");
  lcd.setCursor(0,2);
  lcd.print(humudity_value);
  Serial.print("\n");
  delay(1000); 
  Serial.print(("Temperature: "));
  Serial.print(temprature_value);
  Serial.print(("C "));
  lcd.clear();
  lcd.print("Temperature degCel");
  lcd.setCursor(0,2);
  lcd.print(temprature_value);
  Serial.print("\n");
  delay(1000);
}*/

void moisture_level_detected()
{

  moisture_sensor_value = analogRead(moisture_sensor); 
  Serial.println("Moisture Level : ");
  Serial.println(moisture_sensor_value);
  lcd.clear();
  lcd.print("Moisture Level :");
  lcd.setCursor(0,2);
  lcd.print(moisture_sensor_value);
  delay(2000);
}

void water_motor_start()
{

 {*/
    if(moisture_sensor_value < 700 )
    {
      digitalWrite(relay_Pin, HIGH); 
      delay(2000);
    }
    else
    {
      digitalWrite(relay_Pin, LOW); 
      delay(2000);
    }
 
}

