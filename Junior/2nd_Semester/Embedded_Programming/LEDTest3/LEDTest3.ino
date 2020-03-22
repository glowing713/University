const int ledA = 3, ledB = 5;

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, LOW);
  delay(100);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
  delay(100);
}
