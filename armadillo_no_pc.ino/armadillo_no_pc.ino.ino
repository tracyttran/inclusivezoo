#include <CapacitiveSensor.h>
#include <PCM.h>

CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3); // 1M resistor between pins 2 & 3, pin 3 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);  // 1M resistor between pins 4 & 5, pin 5 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_7 = CapacitiveSensor(6,7); 
CapacitiveSensor   cs_8_9 = CapacitiveSensor(8,9); 

int led1 = 11;
int led2 = 13;

int proximitySensor = 0; // analog pin 0
int distanceVal = 0;
int distanceThreshold = 300;


void setup()                    
{
   cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
   cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_6_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
   cs_8_9.set_CS_AutocaL_Millis(0xFFFFFFFF);
   Serial.begin(9600);
   pinMode(led1,OUTPUT); //LED 1
   pinMode(led2,OUTPUT); // LED 2
}



void loop()                    
{

    long sensor1 =  cs_2_3.capacitiveSensor(50);
    long sensor2 =  cs_4_5.capacitiveSensor(50);
    long sensor3 =  cs_6_7.capacitiveSensor(50);
    long sensor4 =  cs_8_9.capacitiveSensor(50);

    bool sensed = false;
    
  
    distanceVal = analogRead(proximitySensor); 
    //if (distanceVal > distanceThreshold) {
    //  Serial.println("dist");
      //sensed = true;
    //}
      
      
     if(!sensed && sensor1 >= 1000)
     {
        Serial.println("R1");
        digitalWrite(led1,HIGH);
        sensed = true;
     }
  
  
     
     if(!sensed && sensor2 >=1000) {
        Serial.println("R2");
        digitalWrite(led1, HIGH);
        sensed = true;
     }
     if(!sensed && sensor3 >=1000) {
        Serial.println("R3");
        digitalWrite(led1, HIGH);
        sensed = true;
     }
     if(!sensed && sensor4 >=1000) {
        Serial.println("R4");
        digitalWrite(led1, HIGH);
        sensed = true;
     }
  if (sensed) {
    delay(1000);
    digitalWrite(led1, LOW);
  }

}




