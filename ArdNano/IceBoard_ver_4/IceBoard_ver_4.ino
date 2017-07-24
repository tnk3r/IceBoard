#include <EEPROM.h>
// temp3, temp2, temp1 = A5, A6, A7

void setup()  {
  
  Serial.begin(9600);
  Serial.println("IceBoard_rv2_v175");
  Serial.println("Made by .tink3r!");
  printEEPROM();
  printTemp();
  
}

void loop()  {
  
  if (Serial.available() > 0) {
    String message = Serial.readString();
    int speed1 = message.substring(1).toInt();
    int fan = message.substring(0, 1).toInt();
    if (message.substring(0, 3) == "MAX") {
      setAllFanValue(255);
      delay(50);
      printEEPROM();
    } else {
      if (message.substring(0,3) == "MIN"){
          setAllFanValue(10);
          delay(50);
          printEEPROM();
      } else {
        setFanSpeed(fan, speed1);
        Serial.println(message);
        delay(10);
      } 
    }
  } else {
    setPWMFromEEPROM();
    if (EEPROM.read(7) == 250) {
        printEEPROM();
        printTemp();
        EEPROM.write(7, 0);
    } else {
    int val = EEPROM.read(7) + 1;
    EEPROM.write(7, val);
    delay(100);
    }
  }
}

void setPWMFromEEPROM(){
  
    analogWrite(3, EEPROM.read(0));
    analogWrite(5, EEPROM.read(1));
    analogWrite(6, EEPROM.read(2));
    analogWrite(9, EEPROM.read(3));
    analogWrite(10, EEPROM.read(4));
    analogWrite(11, EEPROM.read(5));
}
void printEEPROM(){
  
    Serial.println(1000 + EEPROM.read(0));
    Serial.println(2000 + EEPROM.read(1));
    Serial.println(3000 + EEPROM.read(2));
    Serial.println(4000 + EEPROM.read(3));
    Serial.println(5000 + EEPROM.read(4));
    Serial.println(6000 + EEPROM.read(5));
}

void setFanSpeed(int fan, int speed1){
  
    if (fan == 1) {
      EEPROM.write(0, speed1);
      analogWrite(3, speed1);
    }
    if (fan == 2) {
      EEPROM.write(1, speed1);
      analogWrite(5, speed1);
    }
    if (fan == 3) {
      EEPROM.write(2, speed1);
      analogWrite(6, speed1);
    }
    if (fan == 4) {
      EEPROM.write(3, speed1);
      analogWrite(9, speed1);
    }
    if (fan == 5) {
      EEPROM.write(4, speed1);
      analogWrite(10, speed1);
    }
    if (fan == 6) {
      EEPROM.write(5, speed1);
      analogWrite(11, speed1);
    }
}

void setAllFanValue(int value){
  
      analogWrite(3, value);
      analogWrite(5, value);
      analogWrite(6, value);
      analogWrite(9, value);
      analogWrite(10, value);
      analogWrite(11, value);
      EEPROM.write(0, value);
      EEPROM.write(1, value);
      EEPROM.write(2, value);
      EEPROM.write(3, value);
      EEPROM.write(4, value);
      EEPROM.write(5, value);
}

void printTemp(){
  
      int t1 = analogRead(7);
      int t2 = analogRead(6);
      int t3 = analogRead(5);
      Serial.print("TMP:");
      Serial.print(t1);
      Serial.print(":");
      Serial.print(t2);
      Serial.print(":");
      Serial.print(t3);
      Serial.println(":");
}

