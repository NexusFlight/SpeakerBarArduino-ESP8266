#include <SoftwareSerial.h>
byte incoming = "";
byte incoming2 = "";
//rx 10 tx 11
SoftwareSerial sPort(11,13);


int redButton = 0;
int orangeButton = 2;
int brownButton = 4;
int purpleButton = 10;
int blueButton = 12;

int redState = 0;
int orangeState = 0;
int brownState = 0;
int purpleState = 0;
int blueState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(redButton,INPUT_PULLUP);
  pinMode(orangeButton,INPUT_PULLUP);
  pinMode(brownButton,INPUT_PULLUP);
  pinMode(purpleButton,INPUT_PULLUP);
  pinMode(blueButton,INPUT_PULLUP);
 
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  sPort.begin(9600);
}
//red bt-opt 1
//orange power 2
//brown vol down 3
//purple vol up 4
//blue input 5
void loop() {
  redState = digitalRead(redButton);
  orangeState = digitalRead(orangeButton);
  brownState = digitalRead(brownButton);
  purpleState = digitalRead(purpleButton);
  blueState = digitalRead(blueButton);
  sPort.listen();
  incoming2 = 0;
  if(Serial.available() > 0 || sPort.available() > 0){
    incoming2 = sPort.read(); 
    incoming = Serial.read();
    Serial.println(incoming);
  }

if(orangeState == LOW || purpleState == LOW || brownState == LOW || blueState == LOW || redState == LOW || (incoming2 > 48 && incoming2 < 54)){

  
  if(incoming == 49 ||incoming2 == 49 || brownState == LOW)//
  {
//vol down
  digitalWrite(6,HIGH);
  delay(600);
  digitalWrite(6,LOW);
  }else if(incoming == 50 || incoming2 == 50 || purpleState == LOW) // 
  {
//vol up
  digitalWrite(7,HIGH);
  delay(600);
  digitalWrite(7,LOW);
  }else if(incoming == 51 || incoming2 == 51|| orangeState == LOW )//
  {
//power on
  digitalWrite(8,HIGH);
  delay(1500);
  digitalWrite(8,LOW);
  }else if(incoming == 52 || incoming2 == 52 || blueState == LOW)//
  {
//change state from bluetooth
  digitalWrite(8,HIGH);
  delay(600);
  digitalWrite(8,LOW);
  delay(600);
  digitalWrite(8,HIGH);
  delay(600);
  digitalWrite(8,LOW);
  delay(600);
  digitalWrite(8,HIGH);
  delay(600);
  digitalWrite(8,LOW);
  }
  else if(incoming == 53 || incoming2 == 53 || redState == LOW )//
  {
//change state
  digitalWrite(8,HIGH);
  delay(600);
  digitalWrite(8,LOW);
  }
}
}
