#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int blinknum = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Input Number: ");
}

void loop() {
  if(Serial.available()){
    delay(100);

    lcd.clear();

    if(Serial.available()){
      char num = Serial.read();
      if(isDigit(num)){
        blinknum = (num - '0');
      }

      for(char i = 0; i < blinknum; ++i){
          lcd.noBacklight();
          delay(250);
          lcd.backlight();
          delay(250);
        }
      lcd.write(num);
    }
    

  }
}
