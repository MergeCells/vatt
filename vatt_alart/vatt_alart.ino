
float raw_valu;
float vat_volt;
int hoge;
#define limitVolt_1 10.8
#define limitVolt_2 10.5

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);  
  digitalWrite(13,LOW);
  
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);// LOW
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);// LOW
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  
  
  digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(7,LOW);
  delay(50);
  digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(7,LOW);
  delay(50);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  raw_valu = analogRead(A2);
  vat_volt = raw_valu /1023 * 15;
  // 10.8Vを下回ったら警告①
  // 10.5Vを下回ったら警告②
  // 0 - 1023
  // 0 - 5.00
  // 0 - 15.0
  // 読み取り生データの1が0.01466V
  //Serial.print(vat_volt);
  //Serial.print("\n");
  
  hoge = millis() % 1000;
  
  if(hoge < 200){
    digitalWrite(12,LOW);
  }else if(hoge < 400 && vat_volt < limitVolt_1){
    digitalWrite(12,HIGH);
  }else if(hoge < 600){
    digitalWrite(12,LOW);
  }else if(hoge < 800 && vat_volt < limitVolt_2){
    digitalWrite(12,HIGH);
  }else{
    digitalWrite(12,LOW);
    if(millis()%5000 < 1000){
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
    }
  }
  
  
  delay(205 - millis()%200);
}
