int analogInput_zero = 0;
int analogInput_one = 1;
int analogInput_two = 2;
int analogInput_three = 3;
int analogInput_four = 4;
int analogInput_five = 5;
int value_zero = 0;
int value_one = 0;
int value_two = 0;
int value_three = 0;
int value_four = 0;
int value_five = 0;
String numbers = String();

void setup() {
  Serial.begin(9600);
  pinMode(analogInput_zero, INPUT);
  pinMode(analogInput_one, INPUT);
  pinMode(analogInput_two, INPUT);
  pinMode(analogInput_three, INPUT);
  pinMode(analogInput_four, INPUT);
  pinMode(analogInput_five, INPUT);
}

void loop() {
  value_zero = analogRead(analogInput_zero);
  value_one = analogRead(analogInput_one);
  value_two = analogRead(analogInput_two);
  value_three = analogRead(analogInput_three);
  value_four = analogRead(analogInput_four);
  value_five = analogRead(analogInput_five);
  numbers = value_zero + String(",") + value_one + String(",") + value_two + String(",") + value_three 
  + String(",") + value_four + String(",") + value_five;

  Serial.println(numbers);

  delay(1000);
}
