int ledPin = 11;
int val;
int delay_time = 300;

void setup() {
  pinMode (ledPin, OUTPUT);
}

void loop() {
  val = 250;
  analogWrite(ledPin, val);
  val = val - 100;
  delay(delay_time);
  analogWrite(ledPin, val);
  val = val - 50;
  delay(delay_time);
  analogWrite(ledPin, val);
  val = val - 50;
  delay(delay_time);
  analogWrite(ledPin, val);
  val = val - 30;
  delay(delay_time);
  analogWrite(ledPin, val);
  val = val - 20;
  delay(delay_time);
  analogWrite(ledPin, val);
  delay(delay_time);
}
