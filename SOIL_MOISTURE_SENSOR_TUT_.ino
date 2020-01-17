int soilPin = A0; 
int min = 30; //drowned in water
int max = 900; //dry soil
void setup(){
   pinMode(soilPin,INPUT);
   Serial.begin(9600);
}
void loop(){
   int sensorValue = analogRead(rainPin);
   float percentage = (sensorValue - max)/(min - max);
   Serial.println(percentage);
   delay(1000);
}
