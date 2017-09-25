#include <Wire.h>
#define SLAVE 4
byte count = 'A';
int ledpin = 12;
int ledpin2 = 11;
char temp;
void setup() {
  // put your setup code here, to run once:
  Wire.begin(SLAVE);
  Wire.onReceive(receiveFromMaster);
  Wire.onRequest(sendToMaster);
  pinMode(ledpin, OUTPUT);
  pinMode(ledpin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (temp == 'r'){
    play1();
  }
  else if (temp == 'y'){
    play2();
  }
  else if (temp == 'n'){
    play3();
  }
}

void receiveFromMaster(int bytes) {
  char ch[2];
  for (int i = 0; i < bytes ; i++) {
    ch[i] = Wire.read();
  }
  temp = ch[0];
}

void sendToMaster() {
  Wire.write("4th Arduino");  
}

void play1() {
  digitalWrite(ledpin, HIGH);
  digitalWrite(ledpin2, LOW);
  temp = 0;
}

void play2() {
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin, LOW);
  temp = 0;
}

void play3() {
  digitalWrite(ledpin, LOW);
  digitalWrite(ledpin2, LOW);
  temp = 0;
}

