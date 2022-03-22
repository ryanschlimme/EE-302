import processing.serial.*;

Serial myPort;
int val = 255;

void setup(){
  size(300, 300);                                       //increased box to 300x300 pixels
  myPort = new Serial(this, "COM3", 9600);              //ensured correct port "COM3"
}

void draw(){
  if(keyPressed == true){
    if(key == CODED){
      if(keyCode == DOWN){
        if(val > 100){
          val = val-1;
        }
        println(val);
        myPort.write(val);{
          background(420 - 1.65*val, 1.65*val-165, 0);} //added background line with linear color functions
                                                        //Red ranges from 0 at val=255 to 255 at val=100
                                                        //Green ranges from 255 at val=255 to 0 at val=100
      }
    }
  }
  if(keyPressed == true){                               //utilized the same format code from DOWN arrow to UP arrow
    if(key == CODED){
      if(keyCode == UP){
        if(val < 255){                                  //changed to val < 255 since we can only increase to 255 
          val = val+1;
        }
        println(val);
        myPort.write(val);{
          background(420 - 1.65*val, 1.65*val-165, 0);} //same background line as UP arrow
    }
  }
}
}
