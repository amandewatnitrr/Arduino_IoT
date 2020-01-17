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
radio.openWritingPipe(pipe);
}

void loop() 
{
msg[0] = 1;
radio.write(msg,sizeof(msg));
Serial.println("Lights ON");
digitalWrite(led,msg[0]);
delay(2000);

msg[0] = 0;
radio.write(msg,sizeof(msg));
Serial.println("Lights OFF");
digitalWrite(led,msg[0]);
delay(2000);

}
