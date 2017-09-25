#include <Wire.h>

char myCol[20];
char cha;
int change;

int ENV1 = 3;
int DIR1 = 4;
int ENV2 = 6;
int DIR2 = 7;
int ENV3 = 10;
int DIR3 = 11;

int temp;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  change = 1;
  temp = 0;

  pinMode(ENV1, OUTPUT);
  pinMode(ENV2, OUTPUT);
  pinMode(ENV3, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(DIR3, OUTPUT);
}

void loop() {
  int lf = 1;
  if(Serial.available()){
    Serial.readBytesUntil(lf, myCol, 1);
    if(strcmp(myCol,"r")==0 /*&& change == 1*/){
      /*temp = 1;*/
      digitalWrite(ENV1, HIGH);
      digitalWrite(ENV2, LOW);
      digitalWrite(ENV3, LOW);
      play1();
      /*change = 0;*/
      }
    else  if(strcmp(myCol,"g")==0 /*&& change == 1*/){
      digitalWrite(ENV1, LOW);
      digitalWrite(ENV2, HIGH);
      digitalWrite(ENV3, LOW);
      play2();
      /*change = 0;*/
      }
    else  if(strcmp(myCol,"b")==0 /*&& change == 1*/){
      digitalWrite(ENV1, LOW);
      digitalWrite(ENV2, LOW);
      digitalWrite(ENV3, HIGH);
      play3();
      /*change = 0;*/
      }
    else if(strcmp(myCol,"n")==0 /*&& change == 0*/){
      not_play();
      /*change = 1;*/
    }
      delay(100);
      
  }
  
}

void play1() {
  digitalWrite(DIR1, HIGH);
  delay(2000);
  digitalWrite(DIR1, LOW);
  delay(2000);
}

void play2() {
  digitalWrite(DIR2, HIGH);
  delay(2000);
  digitalWrite(DIR2, LOW);
  delay(2000);
}

void play3() {
  digitalWrite(DIR3, HIGH);
  delay(2000);
  digitalWrite(DIR3, LOW);
  delay(2000);
}

void not_play() {
  digitalWrite(ENV1, LOW);
  digitalWrite(ENV2, LOW);
  digitalWrite(ENV3, LOW);
}
