#include <Wire.h>
#define SLAVE 4
char myCol[20];
char cha;
int change;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  change = 1;
}

void loop() {
  int lf = 10;
  if(Serial.available()){
    Serial.readBytesUntil(lf, myCol, 1);
    if(strcmp(myCol,"r")==0 && change == 1){
      Wire.beginTransmission(SLAVE);
      Wire.write('r');
      Wire.write('\n');
      Wire.endTransmission(SLAVE);
      change = 0;
      }
    else  if(strcmp(myCol,"y")==0 && change == 1){
      Wire.beginTransmission(SLAVE);
      Wire.write('y');
      Wire.write('\n');
      Wire.endTransmission(SLAVE);
      change = 0;
      }
    else if(strcmp(myCol,"n")==0 && change == 0){
      Wire.beginTransmission(SLAVE);
      Wire.write('n');
      Wire.write('\n');
      Wire.endTransmission(SLAVE);
      change = 1;
    }
      delay(10);
      i2c_communication();
      delay(1000);
      
  }
}

void i2c_communication() {
  Wire.requestFrom(SLAVE, 12);
  for (int j = 0 ; j < 12; j++) {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
}

