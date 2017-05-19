
#include <EEPROM.h>

int channel1 = 250;
int channel2 = 250;
int channel3 = 250;
int channel4 = 250;
int channel5 = 250;
int channel6 = 250;

byte value;
  
void setup()  { 
  Serial.begin(9600);
  Serial.println("IceBoard_rv2_v155");
  Serial.println("Made by .tink3r!");
  Serial.println("Mmhwaa-ahaha!");
  Serial.println("send me a 4 digit number,\n Example 4255 to set Channel 4 at 100%");
  Serial.println("");
  Serial.println(1000 + EEPROM.read(0));
  Serial.println(2000 + EEPROM.read(1));
  Serial.println(3000 + EEPROM.read(2));
  Serial.println(4000 + EEPROM.read(3));
  Serial.println(5000 + EEPROM.read(4));
  Serial.println(6000 + EEPROM.read(5));
} 

void loop()  { 

      if (Serial.available() > 0) {
      String message = Serial.readString(); 
      int speed1 = message.substring(1).toInt();
      int fan = message.substring(0,1).toInt();
      Serial.println(message);
      
      if (fan == 1) {
        channel1 = speed1;
        EEPROM.write(0, channel1);
        analogWrite(3, channel1);
      }
      if (fan == 2) {
        channel2 = speed1;
        EEPROM.write(1, channel2);
        analogWrite(5, channel2);
      }
      if (fan == 3) {
        channel3 = speed1;
        EEPROM.write(2, channel3);
        analogWrite(6, channel3);
      }
      if (fan == 4) {
        channel4 = speed1;
        EEPROM.write(3, channel4);
        analogWrite(9, channel4);
      }
      if (fan == 5) {
        channel5 = speed1;
        EEPROM.write(4, channel5);
        analogWrite(10, channel5);
      }
      if (fan == 6) {
        channel6 = speed1;
        EEPROM.write(5, channel6);
        analogWrite(11, channel6);
      }



      Serial.println(message);

      delay(10);
  } else {
    
      channel1 = EEPROM.read(0);
      channel2 = EEPROM.read(1);
      channel3 = EEPROM.read(2);
      channel4 = EEPROM.read(3);
      channel5 = EEPROM.read(4);
      channel6 = EEPROM.read(5);
      
      analogWrite(3, channel1);                    
      analogWrite(5, channel2);                    
      analogWrite(6, channel3);                    
      analogWrite(9, channel4);                    
      analogWrite(10, channel5);                    
      analogWrite(11, channel6);
      delay(10);
  }
}

