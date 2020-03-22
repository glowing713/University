int vRegistor = A0;
int pin_LED[4] = {2,3,4,5};

void setup(){
  Serial.begin(9600);
  
  pinMode(vRegistor, INPUT);
  for(int i = 0; i < 4; ++i){
    pinMode(pin_LED[i], OUTPUT);
    digitalWrite(pin_LED[i], LOW);
  }
}

void loop(){
  int adc = analogRead(vRegistor);
  int count_led = (adc >> 8) + 1;

  for(int i = 0; i < 4; ++i){
    if(i < count_led){
      digitalWrite(pin_LED[i], HIGH);
    }else{
      digitalWrite(pin_LED[i], LOW);
    }
  }

  Serial.println(String("ADC : ") + adc + ", LED count: " + count_led);

  delay(100);
}
