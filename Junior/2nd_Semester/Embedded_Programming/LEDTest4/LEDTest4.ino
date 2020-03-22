const int ledA = 3, ledB = 5;
int brightness = 0, increment = 1;

void setup() {

}

void loop() {
  analogWrite(ledA, brightness);
  analogWrite(ledB, 255 - brightness);

  brightness = brightness + increment;

  if((brightness >= 255) || (brightness <= 0)){
    increment = -increment;
    delay(100);
  }
}
