#include <Wire.h>

int SLAVE[3] = {1, 2, 3};
char myCol[20];
char cha;
int change;
int ledpin = 4;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  change = 1;
  pinMode(ledpin, OUTPUT);
}

void loop() {
  int lf = 1;
  if(Serial.available()){
    Serial.readBytesUntil(lf, myCol, 1);
    if(strcmp(myCol,"r")==0 && change == 1){
      Wire.beginTransmission(SLAVE[0]);
      Wire.write('r');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[0]);
      /*Wire.beginTransmission(SLAVE[1]);
      Wire.write('r');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[1]);
      /*Wire.beginTransmission(SLAVE[2]);
      Wire.write('r');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[2]);*/
      digitalWrite(ledpin, HIGH);
      change = 0;
      }
    else  if(strcmp(myCol,"g")==0 && change == 1){
      Wire.beginTransmission(SLAVE[0]);
      Wire.write('g');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[0]);
     /* Wire.beginTransmission(SLAVE[1]);
      Wire.write('g');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[1]);
      /*Wire.beginTransmission(SLAVE[2]);
      Wire.write('g');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[2]);*/
      digitalWrite(ledpin, LOW);
      change = 0;
      }
    else  if(strcmp(myCol,"b")==0 && change == 1){
      Wire.beginTransmission(SLAVE[0]);
      Wire.write('b');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[0]);
      /*Wire.beginTransmission(SLAVE[1]);
      Wire.write('b');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[1]);
     /* Wire.beginTransmission(SLAVE[2]);
      Wire.write('b');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[2]);*/
      digitalWrite(ledpin, LOW);
      change = 0;
      }
    else if(strcmp(myCol,"n")==0 && change == 0){

      Wire.beginTransmission(SLAVE[0]);
      Wire.write('n');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[0]);
     /* Wire.beginTransmission(SLAVE[1]);
      Wire.write('n');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[1]);
      /*Wire.beginTransmission(SLAVE[2]);
      Wire.write('n');
      Wire.write('\n');
      Wire.endTransmission(SLAVE[2]);*/
      digitalWrite(ledpin, LOW);
      change = 1;
    }
      delay(10);
      //i2c_communication();
      delay(100);
      
  }
}

/*void i2c_communication() {
  Wire.requestFrom(SLAVE[0], 12);
  for (int j = 0 ; j < 12; j++) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
}*/

