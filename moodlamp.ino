
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(A0,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr;
  ldr=analogRead(A0);
  if(ldr<100)
    {
  while(Serial.available()){
  //For red light  
    int a=Serial.read();
    if(a=='1')
  {
    Serial.println("red");
     setColor(255, 0, 0);
     delay(5000);
      }
  //For green light     
  else if(a=='2'){
    Serial.println("green");
     setColor(0, 255, 0);
      delay(5000);
  }
  //For blue  light 
    else if(a=='3'){
    Serial.println("blue");
     setColor(0, 0, 255);
      delay(5000);
    }
  //For yellow  light  
      else if(a=='4'){
    Serial.println("yellow");
     setColor(255,215,0);
      delay(5000);
    }
  //For yellow  light   
      else if(a=='5'){
    Serial.println("purple");
     setColor(128, 0, 128);
      delay(5000);
    }
      
    }
    
}
else if(ldr>100)
{
   setColor(0, 0, 0);
}
}
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(9, red);
  analogWrite(10, green);
  analogWrite(11, blue);  
}
