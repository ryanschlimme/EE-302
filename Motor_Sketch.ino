const int AIN1 = 13;
const int AIN2 = 12;
const int PWA = 11;

void setup() {
  Serial.begin(9600);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWA, OUTPUT);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);

}

void loop() {
  if(Serial.available() > 0) {

    int val = Serial.read();
    Serial.println(val);
    analogWrite(PWA, val);
  }
}
