#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int xAxisPin = 0;
const int yAxisPin = 1;
const int zAxisPin = 2;

const int rightLED = 10;
const int leftLED = 11;
const int upLED = 12;
const int downLED = 13;

void setup(){
  pinMode(zAxisPin, INPUT_PULLUP);
  pinMode(rightLED, OUTPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(upLED, OUTPUT);
  pinMode(downLED, OUTPUT);
    
  lcd.init();
  lcd.backlight();

  lcd.print("ex 6.5");
  lcd.setCursor(0,1);
  lcd.print("Joystick");
  delay(2500);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("X: ");
  lcd.setCursor(0,1);
  lcd.print("Y: ");
  lcd.setCursor(15,1);
}

void loop(){
  int xValue = analogRead(xAxisPin);
  int yValue = analogRead(yAxisPin);
  int zValue = digitalRead(zAxisPin);

  int xDisplay = map(xValue, 0, 1023, 6, 15);
  int yDisplay = map(yValue, 0, 1023, 6, 15);

  lcd.setCursor(2,0);
  lcd.print("              ");

  lcd.setCursor(2,0);
  lcd.print(xValue);

  lcd.setCursor(xDisplay, 0);
  lcd.print("|");

  if(xValue < 412){
    digitalWrite(leftLED, HIGH);
    delay(500);
    digitalWrite(leftLED, LOW);
    delay(500);
  }else if(xValue > 612){
    digitalWrite(rightLED, HIGH);
    delay(500);
    digitalWrite(rightLED, LOW);
    delay(500);
  }

  lcd.setCursor(2,1);
  lcd.print("              ");

  lcd.setCursor(2,1);
  lcd.print(yValue);

  lcd.setCursor(yDisplay, 1);
  lcd.print("|");

  if(yValue < 412){
    digitalWrite(upLED, HIGH);
    delay(500);
    digitalWrite(upLED, LOW);
    delay(500);
  }else if(yValue > 612){
    digitalWrite(downLED, HIGH);
    delay(500);
    digitalWrite(downLED, LOW);
    delay(500);
  }

  if(zValue == LOW){
    lcd.noBacklight();
    delay(300);
    lcd.backlight();
    digitalWrite(rightLED, HIGH);
    digitalWrite(leftLED, HIGH);
    digitalWrite(upLED, HIGH);
    digitalWrite(downLED, HIGH);
    delay(500);
    digitalWrite(rightLED, LOW);
    digitalWrite(leftLED, LOW);
    digitalWrite(upLED, LOW);
    digitalWrite(downLED, LOW);
  }
  delay(100);
}
