void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if(Serial.available()){   // 데이터가 뭐든 들어오기만 하면
    byte data = Serial.read();  // 1바이트 단위로 읽기

    Serial.print("Echo back: ");
    Serial.write(data);   // ASCII 문자로
    Serial.print(" ");
    Serial.println(data); // 숫자로
  }
}
