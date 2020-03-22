void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  String str1 = "One String", str2 = "Another String";
  int n = 1234;
  float f = 3.14;
  char c = 'A';

  Serial.println(str1);
  Serial.println(str1 + " " + str2);

  Serial.println(String(n));  // 정수로부터 10진 문자열 생성
  Serial.println(String(n,BIN));  // 2진 문자열 생성
  Serial.println(String(n,HEX));  // 16진 문자열 생성

  //Serial.println(String(f));  // 실수의 경우는 문자열로 직접 변환 안된다.
  Serial.println(f);
  Serial.println("String + Integer: " + String(n));

  String str3 = "String + character: ";
  str3 += n;
  Serial.println(str3);

  while(true);
}
