const int ledPin = 13;  // 출력할 핀 번호
int blinkNumber = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);  
}

void loop() {
  int count = 0;
  
  if(Serial.available()){
    char val = Serial.read();

    if(isDigit(val)){ // 입력받은 수가 10진수 맞는가. 0~9
      blinkNumber = (val - '0');
    }
  }
  for(int i = 0; i < blinkNumber; ++i){
    ++count;
    digitalWrite(ledPin,HIGH);
    delay(200);
    digitalWrite(ledPin,LOW);
    delay(200);

    Serial.println(count);
  }
  blinkNumber = 0;  // 다시 초기화
}
