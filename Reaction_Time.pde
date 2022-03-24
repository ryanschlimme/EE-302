PFont f; //set f to represent a font
float randomNum = random(100, 5000); //randomNum will be a floating point value between 100 and 5000

// void represents a function that returns no value
// setup represents a function that is not looped and just initializes values
void setup() {
  frameRate(240); //sets rate at which the program operates
  f = createFont("Arial", 30, true); //sets font to Arial size 30 pts and says that the font is anti-aliased
  background(255,100,100); //sets background to RBG value 255,100,100
  textFont(f); //sets font to the created font stored as f
  fill(0); //fills the background with 0
  text("When the square turns green, \nhold down the space bar.", 100, 300); //displays the following text at (x,y) coordinates (100,300) with a line break 
                                                                             //at \n
  size(700, 700); //sets the box to size 700 x 700 pixels
}

// draw continuously executes the code until noLoop()
void draw() {
  int m = millis(); //set m as an integer value of milliseconds elapsed
  println(m); //print m to the console
  
  if(m > (3000 + randomNum)){ //if m is greater than 3000 + the random number (ms), continue
    background(100, 255, 100); //change the background to RGB color 100,255,100 (green)
    if(keyPressed == true){ //if you press a key
      if(key == ' '){ //and that key is space
        text("space was pressed " + (m - (3000 + randomNum)) + " msec", 100, 300); //print the string at (x,y) coordinate 100,300
        println(randomNum); //print the random number to the console
        noLoop(); //stops the loop
      }
    }
  }
  delay(1); //delay 1 ms
}
