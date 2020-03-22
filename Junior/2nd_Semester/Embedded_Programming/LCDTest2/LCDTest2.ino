#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0,0);
  for(int i = 0; i < 16; ++i){
    lcd.write(0x61 + i);
  }
  lcd.setCursor(0,1);
  for(int j = 16; j < 26; ++j){
    lcd.write(0x61 + j);
  }
}

void loop() {

}
