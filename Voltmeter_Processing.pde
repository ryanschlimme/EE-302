import processing.serial.*;
Serial arduino;
String arduinoInput;
PFont f;
String[] list;


void setup() {
  f = createFont("Arial",20,true);
  size(700, 700);
  printArray(Serial.list());
  arduino = new Serial(this, "COM3", 9600);
}

void draw() {
  if (arduino.available()>0)
  {
    background(255);
    arduinoInput=arduino.readString();
    println(arduinoInput);
    
      String m = arduinoInput;
      list = split(m, ",");
      if(list.length == 6){
        float zero = float(list[0]);
        float one = float(list[1]);
        float two = float(list[2]);
        float three = float(list[3]);
        float four = float(list[4]);
        float five = float(list[5]);
        textFont(f);
        fill(0);
        
       text("Analog Input 0: " +nf((zero*5)/1024,0,3) + " V", 100,100);
       text("\n" + "Analog Input 1: " +nf((one*5)/1024,0,3) + " V", 100,100);
       text("\n" + "\n" + "Analog Input 2: " +nf((two*5)/1024,0,3) + " V", 100,100);
       text("\n" + "\n" + "\n" + "Analog Input 3: " +nf((three*5)/1024,0,3) + " V", 100,100);
       text("\n" + "\n" + "\n" + "\n" + "Analog Input 4: " +nf((four*5)/1024,0,3) + " V", 100,100);
       text("\n" + "\n" + "\n" + "\n" + "\n" + "Analog Input 5: " +nf((five*5)/1024,0,3) + " V", 100,100);
      }
      delay(1000);
  }
}
