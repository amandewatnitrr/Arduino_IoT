#include <VirtualWire.h>
#include <VirtualWire_Config.h>
#include<SD.h>
#include<SPI.h>
#include<Wire.h>

char message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;

void setup()
{

 Serial.begin(9600);
 vw_setup(2000);
 vw_set_rx_pin(11);
 vw_rx_start();
 Serial.println("Device is Ready....");
  
}

void loop()
{

  if(vw_get_message( message,&messageLength))
  {
    
   Serial.print("Message Recieved:");
   for(int i=0;i<messageLength;i++)
      {
       Serial.print(message[i]); //must be message[i]
      }
   Serial.println();
   delay(300);  
  }

}
