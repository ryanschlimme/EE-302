int digitalInput = 2; //selects digital input integer 2 on the SparkFun RedBoard
int digitalOutput = 10; //selects digital output integer 10 on the SparkFun RedBoard
int randomDelay = 0; //initializes an integer variable "randomDelay" to 0 
int val = 0; //initializes an integer variable "val" to 0
int counter = 0; //initializes an integer variable "counter" to 0
int incoming = 0; //initializes an integer variable "incoming" to 0

// void indicates a function that does not return information
// setup initializes the program
void setup() {

  Serial.begin(9600); //sets the data rate as 9600 bits per second between serial monitor and program
  pinMode(digitalInput, INPUT); //digitalInput is set as the INPUT of data
  pinMode(digitalOutput, OUTPUT); //digitalOutput is set as the OUTPUT of data
  Serial.println("Are you ready to test your reaction time? Press 1 to start each round."); //prints the string to the monitor
  delay(1000); //delay 1000 ms or 1 second

}
//loop indicates that the following code should be repeated, variable values CAN change between iterations
void loop() {
  if(Serial.available() > 0){ //if the available bytes is more than 0, ie a button was pressed
    incoming = Serial.read(); //read the character
    if (incoming == 49){ //if the character is the 1 key, then continue
      randomDelay = random(10, 4000); //set randomDelay to an integer between 10 and 4000 ms
      Serial.println("Listen for the buzzer, then press the button."); //print the string to the console
      delay(randomDelay); //initiate the delay
      analogWrite(digitalOutput, 262); //asserts an anlog wave to the output pin, the duty cycle is set to always on
      val = digitalRead(digitalInput); //sets val to the binary value of the input pin (either 0 or 1)
      while(val == HIGH){ //if val is logic 1 (or HIGH) proceed
        val = digitalRead(digitalInput); //set val to the binary value of the input pin
        delay(10); //wait 10 ms
        counter = counter + 10; //increment counter by 10 ms
      }
    digitalWrite(digitalOutput, LOW); //set output pin to logic 0
    Serial.println("Your reaction time: " +String(counter) + " msec."); //print reaction time as a string with the value of counter as a string
    counter = 0; //return counter to 0
    }
  }
  delay(100); //wait 100 ms
}
