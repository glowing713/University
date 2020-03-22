#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  for(int i = 48; i < 58; ++i){
    int locat = i / 2;
    if(i % 2 == 0){
      lcd.setCursor(locat - 24,0);
      lcd.write(i);
    }
    lcd.setCursor(locat - 24,1); 
    lcd.write(i);
  }
}

void loop() {

}
