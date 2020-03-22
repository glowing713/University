void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("String: ");
  Serial.println("Test string");

  Serial.print("Char: ");
  Serial.println('c');

  Serial.print("Integer: ");
  Serial.println(123);

  Serial.print("Float: ");
  Serial.println(3.14);

  byte data = 65; // ASCII 코드 대문자 A
  Serial.println(); // 한 줄 개행
  
  while(true);
}
