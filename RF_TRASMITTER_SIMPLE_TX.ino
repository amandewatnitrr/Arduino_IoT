#include<VirtualWire.h>
#include<SD.h>
#include<SPI.h>
#include<Wire.h>

void setup()
{
  
 vw_setup(2000);
 vw_set_tx_pin(12);
 
Serial.println("Start to Send Message to Other Arduino Wirelessly...");  
}

void loop()
{
Serial.println("Sending Message to Other Arduino Wirelessly...");  
char message[]="Hello World";
vw_send( (uint8_t*)&message,strlen(message));
vw_wait_tx();

}
