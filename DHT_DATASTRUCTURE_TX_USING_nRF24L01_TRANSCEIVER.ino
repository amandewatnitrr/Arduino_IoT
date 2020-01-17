#include<DHT.h>
#include<SD.h>
#include<Wire.h>
#include<RF24.h>
#include<SPI.h>
#define DHTPIN  A0    
#define DHTTYPE DHT11   
DHT dht(DHTPIN,DHTTYPE);
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
dht.begin();
radio.begin();
radio.openWritingPipe(pipe);
}

void loop() 
{
dhtvar.h = dht.readHumidity();
dhtvar.t = dht.readTemperature();
dhtvar.hic = dht.computeHeatIndex(dhtvar.t,dhtvar.h,false);
Serial.print("Humidity = ");
Serial.println(dhtvar.h);
Serial.print("Temperature = ");
Serial.println(dhtvar.t);
Serial.print("Heat Index = ");
Serial.println(dhtvar.hic);
Serial.println();
radio.write(&dhtvar,sizeof(dhtvar));
if(radio.available())
{Serial.println("Information Sent");}
*dhtvar.count++;
delay(1000);
}
