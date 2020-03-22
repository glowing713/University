void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int n = 123;
  float f = 3.1415927;

  Serial.println(n,BIN);  // 2진수
  Serial.println(n,DEC);  // 10진수
  Serial.println(n,HEX);  // 16진수

  Serial.println();
  Serial.print(f);
  Serial.print(f,5);  // 소수점 이하 5자리 표현

  while(true);
}
