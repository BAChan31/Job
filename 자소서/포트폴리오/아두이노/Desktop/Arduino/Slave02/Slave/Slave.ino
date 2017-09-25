#include <Wire.h>
#define SLAVE 1
int ENV = 8;
int DIR = 9;
char temp;
int dir;
void setup() {
  // put your setup code here, to run once:
  Wire.begin(SLAVE);
  Wire.onReceive(receiveFromMaster);
  //Wire.onRequest(sendToMaster);
  pinMode(ENV, OUTPUT);
  pinMode(DIR, OUTPUT);
  dir = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (temp == 'r') {
    digitalWrite(ENV, HIGH);
    play1();
  }
  else if (temp == 'g') {
    play2();
  }
  else if (temp == 'b') {
    play2();
  }
  else if (temp == 'n') {
    play2();
  }
}

void receiveFromMaster(int bytes) {
  char ch[2];
  for (int i = 0; i < bytes ; i++) {
    ch[i] = Wire.read();
  }
  temp = ch[0];
}

/*void sendToMaster() {
  Wire.write("1st Arduino");
}
*/
void play1() {

  digitalWrite(DIR, LOW);
  delay(2000);
  digitalWrite(DIR, HIGH);
  delay(2000);

}

void play2() {
  digitalWrite(ENV, LOW);
  temp = 0;
  dir = 0;
}


