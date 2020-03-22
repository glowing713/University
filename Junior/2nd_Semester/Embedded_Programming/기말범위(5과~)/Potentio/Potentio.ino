const int potentioMeterPin = A0;

// const int ledPin을 13번과 같은 digitalPin으로 하면 on/off 둘밖에 없지만
// 3, 5, 6, 9, 10, 11인 analogPin으로 하면 밝기가 조절이 된다.
const int ledPin = 3;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int adcValue;
  int duty;

  adcValue = analogRead(potentioMeterPin);
  duty = map(adcValue, 0, 1023, 0, 255);

  analogWrite(ledPin, duty);
}
