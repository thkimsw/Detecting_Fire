#include <SoftwareSerial.h>
#define Tx 2
#define Rx 3
#define flame 7 // 불꽃감지 센서
#define Sound 8

int state = 0; //state means value of frame_detect_sensor state High = detecting,  Low = no_detecting
              //In testing, switch state manually
int tones[] = {261, 294, 330, 349, 392, 440, 494, 523};
int numTones = 8;           
SoftwareSerial HC05(Tx,Rx);


void setup() {
  Serial.begin(9600);
  HC05.begin(9600);
  pinMode(flame,INPUT);
  pinMode(Sound,OUTPUT);    
}

void loop() {
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
      
         for (int i = 0; i < numTones; i++) {
      tone(Sound, tones[i]);
      delay(10);
    }
    noTone(Sound);
    
    delay(10); //1s = 1000ms delay(milli second);
    }
}
