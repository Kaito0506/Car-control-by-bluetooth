#include <SoftwareSerial.h>
SoftwareSerial sig(2, 3); // RX, TX

int enbA=3;
int in1 = 4;       
int in2 = 5;        
int in3 = 6;        
int in4 = 7;  
int enbB=13;    
char input; 

////led BGR
//int red=10;
//int green=11;
//int blue=12;
////sieu am sensor
//int trig=8;
//int echo=9;
//int margin = 15; // distance to regconize objects
//
//unsigned long timex; 
//int distance; 


void setup() {
  sig.begin(9600);
  Serial.begin(115200);
//  pinMode(red, OUTPUT);
//  pinMode(green, OUTPUT);
//  pinMode(blue, OUTPUT);
}

void loop() {
  if(sig.available())
  {
    input=sig.read();
    
    switch(input){
    case 'S':
    Serial.println(input );
    STOP(); 
//    digitalWrite(red, LOW);
//    digitalWrite(blue, LOW);
//    digitalWrite(green, HIGH);
    break;
    
    case 'F':
    Serial.println(input);
    FORWARD();
//    digitalWrite(red, LOW);
//    digitalWrite(blue, LOW);
//    digitalWrite(green, HIGH);
    break;

    case 'B':
    Serial.println(input);
    BACKWARD();
//    digitalWrite(red, HIGH);
//    digitalWrite(blue, HIGH);
//    digitalWrite(green, HIGH);
    break;

    case 'R':
    Serial.println(input);
    RIGHT();
//    digitalWrite(red, HIGH);
//    digitalWrite(blue, LOW);
//    digitalWrite(green, HIGH);
    break;

    case 'L':
    Serial.println(input);
    LEFT();
//    digitalWrite(red, HIGH);
//    digitalWrite(blue, LOW);
//    digitalWrite(green, HIGH);
    break;
   }
  }
//  else{// not connected
//    digitalWrite(red, HIGH);
//    digitalWrite(blue, LOW);
//    digitalWrite(green, LOW);
//  //  delay(500);
//    digitalWrite(red, LOW);
//    digitalWrite(blue, HIGH);
//    digitalWrite(green, LOW);
//    delay(500);
//    digitalWrite(red, LOW);
//    digitalWrite(blue, LOW);
//    digitalWrite(green, HIGH);
//    delay(500);
////  }
//  distance = 0;
//  DISTANCE();
//  if(distance<=margin)
//  {
//    digitalWrite(red, HIGH);
//    digitalWrite(blue, LOW);
//    digitalWrite(green, LOW);
//    delay(800);
//    digitalWrite(red, LOW);
//    digitalWrite(blue, LOW);
//    digitalWrite(green, LOW);
//  }
}

//function to control car
void FORWARD()
{
  analogWrite(enbA, 100);
  analogWrite(enbB, 100);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);


}
void STOP(){
  analogWrite(enbA, 0);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  }

void RIGHT()
{
   analogWrite(enbA, 100);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);


}
void LEFT()
{
  analogWrite(enbA, 0);
  analogWrite(enbB, 100);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}

void BACKWARD()
{
  analogWrite(enbA, 100);
  analogWrite(enbB, 100);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

}

//void DISTANCE()
//{
//
//  digitalWrite(trig, LOW); 
//  delayMicroseconds(2);
//  digitalWrite(trig, HIGH);  
//  delayMicroseconds(10); 
//  digitalWrite(trig, LOW); 
//
//  unsigned long timex; 
//  int distance;  
//  // Đo độ rộng xung HIGH ở chân echo.
//  timex = pulseIn(echo, HIGH);
//
//  distance = timex/ 2 / 29.412;
//
//}
