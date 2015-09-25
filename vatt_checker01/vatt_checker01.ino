void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(13, OUTPUT);
}

void loop() {

  // バッテリー電圧1
  // 公称電圧12V・満充電時12.63V・完全放電目安10.5V
  // 無警告11.5V・アラート11V・停止指示11V未満
  // アナログ入力は分圧抵抗によって1/3の電圧が得られる
  // 0-15V を 0-1024 に変換される
  // 無警告758・アラート750・停止指示750未満
  if (analogRead(A0) < 750) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  } else if (analogRead(A0) < 758) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  // バッテリー電圧2
  if (analogRead(A1) < 750) {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  } else if (analogRead(A0) < 758) {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }


  // 出力電圧
  // 公称19V・目標18.5V・危険水準17V
  // 無警告18V・アラート17V・停止指示17V未満
  // 分圧抵抗によって1/4の電圧が得られる
  // 0-20V を 0-1024 に変換される
  // 無警告948・アラート870・停止指示870未満
  if (analogRead(A3) < 870) {
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  } else if (analogRead(A0) < 948) {
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  } else {
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  digitalWrite(13, HIGH);
  delay(50);
  
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

  digitalWrite(11, LOW);
  digitalWrite(10, LOW);

  digitalWrite(13, LOW);
  delay(50);
}
