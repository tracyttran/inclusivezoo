

int resetButton = 12;


void setup()                    
{
  Serial.begin(9600);
   pinMode(resetButton, INPUT); 
}



void loop()                    
{
  Serial.println(digitalRead(resetButton)); 
  delay(100);
} 
