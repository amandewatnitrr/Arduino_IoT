#include<SPI.h>
#include<RF24.h>

byte msg[1];
RF24 radio(7,8);
int led = 5;
const uint64_t pipe = 0x8675309ABCll;

void setup() 
{
Serial.begin(9600);
pinMode(led,OUTPUT);
radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
}

void loop() 
{
if(radio.available())
  {
   radio.read(msg,sizeof(msg));
   Serial.print("Message Recived -> ");
   Serial.println(msg[0]);
   if(msg[0]==1)
     {
      digitalWrite(led,1);
      Serial.println("Lights ON");
      delay(2000);
     }
   else if(msg[0]==0)
     {
      digitalWrite(led,0);
      Serial.println("Lights OFF");
      delay(2000);
     }
    else
     {
      Serial.println("No Message Recived...");
     }
   }
}
