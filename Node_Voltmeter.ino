#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 10000.0;
float R2 = 10000.0;
int value = 0;
int a[5] = {};

void setup() {
  Serial.begin(9600);
  pinMode(analogInput, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("DC VOLTMETER");
  lcd.setCursor(0, 1);
  lcd.print("-RYAN SCHLIMME-");
  delay(3000);
  lcd.clear();

}

void loop() {
  lcd.print("DC Voltmeter");
  value = analogRead(analogInput);
  vout = (value * 5) / 1024.0;
  vin = vout / (R2 / (R1 + R2));
  Serial.println(vin);
  if (vin < 0.09)
  {
    vin = 0.0;
  }
  lcd.setCursor(0, 1);
  lcd.print("Voltage V :");
  lcd.print(vin);
  delay(3000);
  lcd.clear();
}
