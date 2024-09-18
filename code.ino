//part 1: ----------------------------------------
#include <OneWire.h>
#include <DallasTemperature.h>   // importing the libraries

//part 2:-----------------------------------------

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const int fanPin = 4;  
const int HeatPin = 6;

void setup(){                           //THIS IS SETUP FOR SEGMENTS!!
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
  sensors.begin();

}

//part 3:---------------------------------------
void loop(){
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  Serial.print("Temperature:");
  Serial.println("");
  Serial.print(tempC);
  Serial.print("value:");
  //delay(1000);

  if (tempC > 43.00){
    digitalWrite(HeatPin, LOW);
    digitalWrite(fanPin, HIGH);
    //delay(8000);
    //digitalWrite(fanPin, LOW);
    Serial.print("done");
    Serial.println("");
  }

  else if (tempC < 35.00)
  {
    digitalWrite(fanPin, LOW);
    digitalWrite(HeatPin, HIGH);
    Serial.print("low");
    Serial.println("");
  }
//delay(1000);



}
