#include <SoftwareSerial.h>
SoftwareSerial myserial (5,6) ;// bluetooth : Tx = 5 , Rx = 6  

int MQ9=A0;
int MQ6=A0;


void setup() 
{
  pinMode(MQ6,INPUT);
  pinMode(MQ9,INPUT);
  Serial.begin(9600);
  {
myserial.begin(9600); 
Serial.begin (9600) ;  

}
}
 
void loop() 
{
  float sensorVoltageMQ9; 
  float sensorValueMQ9;
  sensorValueMQ9 = analogRead(MQ9);
  sensorVoltageMQ9 = sensorValueMQ9/1024*5.0;
  Serial.print("CO2 = ");
  Serial.print(sensorValueMQ9);
  Serial.println("PPM");
  delay(100);
  if(myserial.available() )
  {
    Serial.write( myserial.read() ); 
    }
    if (Serial.available () )
    {
      myserial.write(Serial.read() );
      }
 int sensorValueMQ6 = analogRead(MQ6);
  //Serial.println(sensorValueMQ6);
  Serial.print("LPG and butane = ");
  Serial.print(sensorValueMQ6);
  Serial.println("PPM");
  delay(10000);
}
