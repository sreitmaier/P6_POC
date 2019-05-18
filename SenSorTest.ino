#include "Grove-Ultrasonic-Ranger.h"
#include "Grove_Temperature_And_Humidity_Sensor.h"

#define DHTPIN 	D2     // set pin for Humidity

DHT dht(DHTPIN);

Ultrasonic ultrasonic(D4); // set pin for Distance Measure 
void setup()
{
	Serial.begin(9600);
	Serial.println("DHT11 Begin!!!");

	dht.begin();
}
void loop()
{
	long RangeInInches;
	long RangeInCentimeters;
	
	Serial.println("The distance to obstacles in front is: ");
	RangeInInches = ultrasonic.MeasureInInches();
	Serial.print(RangeInInches);//0~157 inches
	Serial.println(" inch");
	delay(250);
	
	RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
	Serial.print(RangeInCentimeters);//0~400cm
	Serial.println(" cm");
	delay(250);

	
	delay(1000);



//Read Humidity
	float h = dht.getHumidity();
// Read temperature as Celsius
	float t = dht.getTempCelcius();
// Read temperature as Farenheit
	float f = dht.getTempFarenheit();

// Check if any reads failed
	if (isnan(h) || isnan(t) || isnan(f))
	{
		Serial.println("Failed to read from DHT11 sensor!");
		return;
	}

	Serial.print("Humid: ");
	Serial.print(h);
	Serial.println("%  ");
	Serial.print("Temp: ");
	Serial.print(t);
	Serial.println("*C ");
	Serial.print("Temp: ");
	Serial.print(f);
	Serial.println("*F ");
	Serial.println();Serial.println();



	
}
