#include <CapacitiveSensor.h>
#include <PCM.h>

CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_10_13 = CapacitiveSensor(10,13);  // 1M resistor between pins 10 & 13, pin 13 is sensor pin, add a wire and or foil

// buzzer sample
int buzzer = 2;
int songLength = 17;
char notes[] = "cdaf gf adfgc gc ";
int beats[] = {1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,3};
// A "1" represents a quarter-note, 2 a half-note
int tempo = 130;
//how fast to play the song

void setup()                    
{
   cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
   cs_10_13.set_CS_AutocaL_Millis(0xFFFFFFFF);
   Serial.begin(9600);
   pinMode(7,OUTPUT); //LED 1
   pinMode(11,OUTPUT); // LED 2
   pinMode(buzzer, OUTPUT); 
}

int frequency(char note) 
{

  int i;

  const int numNotes = 8; // number of notes stored

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}

void loop()                    
{
 long sensor1 =  cs_4_8.capacitiveSensor(50);
  long sensor2 =  cs_10_13.capacitiveSensor(50);

    
    
   if(sensor1 >= 1000)
   {
    Serial.println(sensor1);  // print sensor output 
    digitalWrite(7,HIGH);
   }
   else{
    digitalWrite(7,LOW);
   }  

   int i, duration;
   
   if(sensor2 >=1000) {
    digitalWrite(11, HIGH);
     for (i = 0; i < songLength; i++)
    {
      duration = beats[i]*tempo;

      if (notes[i] == ' ')
      {
        delay(duration);
      }
      else
      {
        tone(buzzer, frequency(notes[i]), duration);
      delay(duration);
      }
      delay(tempo/10);
      // brief pause between notes
    }
   }else {
    digitalWrite(11, LOW);
   }
}


