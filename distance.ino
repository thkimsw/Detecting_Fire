#include <SoftwareSerial.h>
SoftwareSerial HC05(2,3); // RX,TX
#define trig1 3
#define echo1 4
#define LED1  5
#define trig2 6
#define echo2 7
#define LED2  8
#define trig3 9
#define echo3 10
#define LED3  11
#define flame 8
int state = 0;

void setup() {
  Serial.begin(9600);
  HC05.begin(9600);
  pinMode(flame,INPUT);
  pinMode(LED1,OUTPUT); //door_1 led. setup port should be defined
  pinMode(LED2,OUTPUT); //door_1 led. setup port should be defined
  pinMode(LED3,OUTPUT); //door_1 led. setup port should be defined
  
} 

void loop() {
    long duration1, distance1;
    long duration2, distance2;
    long duration3, distance3;
    
    state = digitalRead(flame);
    Serial.print('\n');
    Serial.print(state);
    if(state != 0){
        Serial.print('\n');
        Serial.print("false");
        Serial.print('\n');
        HC05.write("false");
        HC05.write('\n');
      }
   else{
      Serial.print('\n');
      Serial.print("true");
      Serial.print('\n');HC05.write("true");
      HC05.write('\n');

    digitalWrite(trig1, LOW);        //Trig 핀 Low
    delayMicroseconds(2);            //2us 유지
    digitalWrite(trig1, HIGH);    //Trig 핀 High
    delayMicroseconds(10);            //10us 유지
    digitalWrite(trig1, LOW);        //Trig 핀 Low
 
    //Echo 핀으로 들어오는 펄스의 시간 측정
    duration1 = pulseIn(echo1, HIGH);       
    distance1 = duration1 / 29 / 2;
    Serial.print("DIS1 : ");
    Serial.print(distance1);
    Serial.print("cm");
    Serial.println();

    if(distance1>50){
      digitalWrite(LED1,HIGH);
      }
    else{
      digitalWrite(LED1,LOW);
      }

    digitalWrite(trig2, LOW);        //Trig 핀 Low
    delayMicroseconds(2);            //2us 유지
    digitalWrite(trig2, HIGH);    //Trig 핀 High
    delayMicroseconds(10);            //10us 유지
    digitalWrite(trig2, LOW);        //Trig 핀 Low
 
  
    duration2 = pulseIn(echo2, HIGH);       
    distance2 = duration2 / 29 / 2;
    Serial.print("DIS1 : ");
    Serial.print(distance2);
    Serial.print("cm");
    Serial.println();

    if(distance2>50){
      digitalWrite(LED2,HIGH);
      }
    else{
      digitalWrite(LED2,LOW);
      }

    digitalWrite(trig3, LOW);        //Trig 핀 Low
    delayMicroseconds(2);            //2us 유지
    digitalWrite(trig3, HIGH);    //Trig 핀 High
    delayMicroseconds(10);            //10us 유지
    digitalWrite(trig3, LOW);        //Trig 핀 Low
 
    //Echo 핀으로 들어오는 펄스의 시간 측정
    duration3 = pulseIn(echo3, HIGH);       
    distance3 = duration3 / 29 / 2;
    Serial.print("DIS1 : ");
    Serial.print(distance3);
    Serial.print("cm");
    Serial.println();

    if(distance3>50){
      digitalWrite(LED3,HIGH);
      }
    else{
      digitalWrite(LED3,LOW);
      }
      
    delay(100);
}
}
