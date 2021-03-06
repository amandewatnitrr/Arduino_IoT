#include<DHT.h>
#include<ESP8266WiFi.h>
#define DHTTYPE DHT11
#define DHTPIN D0

DHT dht(DHTPIN,DHTTYPE);

String apikey = "5ANH7HF83IEQ5HFW";
const char* ssid = "Akd";
const char* pwd = "12345678";
float h;
float t;
float hic;
float tsdata;
#define WEBSITE "api.thingspeak.com"


void setup()
{
  Serial.begin(115200);
  dht.begin();
  Serial.print("Connecting to"+ *ssid);
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED)
       {
        delay(1000);
        Serial.print(".");
       }
  Serial.println();
  Serial.println("Credentials Accepted !! Connected to WiFi");
  Serial.println();
}

void loop()
{

delay(2000);

t= dht.readTemperature();
h= dht.readHumidity();
hic = dht.computeHeatIndex();

Serial.println();
Serial.print("Humidity = ");
Serial.println(h);
Serial.print("Temperature = ");
Serial.println(t);
Serial.print("Heat Index = ");
Serial.println(hic);
Serial.println();

WiFiClient client;

if(client.connect(WEBSITE,80))
  {
   Serial.println("WiFi Client Connected !!! ");
   client.print(F("POST"));
   client.print("https://api.thingspeak.com/update?api_key=5ANH7HF83IEQ5HFW&field1="
   +(String)h
   +"&field2="
   +(String)t+"&field3="
   +(String)hic);
   

   client.print("POST /update HTTP/1.1\n");
   client.print("Host: api.thingspeak.com\n");
   client.print("Connection: close\n");
   client.print("X-THINGSPEAKAPIKEY: "+apikey+ "\n");
   client.print("Content-Type: application/x-www-form-urlencoded\n");
   
  }

else{Serial.println("Couldnot connect to ThingSpeak");}

client.stop();

    
}
 