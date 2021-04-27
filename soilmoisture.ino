
#define SensorPin A0
#define Baudrate 9600
#define Pump 13
#define relay 11
float sensorValue = 0; 
float outputvalue = 0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(Baudrate);
pinMode(SensorPin,INPUT);
pinMode(Pump,OUTPUT);
digitalWrite(Pump,LOW);
pinMode(relay,INPUT);

}

void loop() {
 //  put your main code here, to run repeatedly:
 for (int i = 0; i <= 100; i++) 
 {  
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue); 
 delay(30); 
 if(sensorValue > 800)
 {
  digitalWrite(Pump,HIGH);
 
 }
 else if(sensorValue < 500)
 {
  digitalWrite(Pump,LOW);
 }
 
 outputvalue = digitalRead(relay);
 Serial.println(outputvalue);
 delay(400);
 



}
