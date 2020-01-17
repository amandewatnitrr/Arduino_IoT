#include<SD.h>
#include<Wire.h>
#include<RF24.h>
#include<SPI.h>      
RF24 radio(7,8);
const uint64_t pipe = 0x8675309ABCll;

struct dhtdata
{
float h;
float t;
float hic;
int *count;  
};

dhtdata dhtvar;

void setup() 
{
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
}

void loop() 
{
radio.read(&dhtvar,sizeof(dhtvar));
Serial.print("Humidity = ");
Serial.println(dhtvar.h);
Serial.print("Temperature = ");
Serial.println(dhtvar.t);
Serial.print("Heat Index = ");
Serial.println(dhtvar.hic);
Serial.print("Counter = ");
Serial.println(*dhtvar.count);
Serial.println("\n \n");
delay(2000);
}
