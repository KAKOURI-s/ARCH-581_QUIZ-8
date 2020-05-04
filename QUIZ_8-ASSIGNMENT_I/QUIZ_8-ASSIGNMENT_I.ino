#include <Servo.h>
Servo myServo;

const int POT1_PIN = A0; // POT1 = rotation speed
const int POT2_PIN = A1; // POT2 = range control

int POT1Val;
int POT2Val;
int angle; // ServoValue
int speed;
int ServoState=0;
// const int minAngle =0;
//const int maxAngle = 179;

void setup() {
  // put your setup code here, to run once:
  myServo.attach (10);
  Serial.begin(9600);
  myServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  POT1Val = analogRead(POT1_PIN);
  POT2Val = analogRead(POT2_PIN);
  Serial.print("POT1Val:");
  Serial.print(POT1Val);
  Serial.print(",");
  Serial.print("POT2Val");
  Serial.print(POT2Val);
  Serial.print(",");
  angle = map(POT2Val, 0, 1023, 0, 179);
  speed = map(POT2Val, 0, 1023, 100, 0);
  
  Serial.print("angle:");
  Serial.print(angle);
  Serial.print(",");
  Serial.print("speed:");
  Serial.println(speed);
  myServo.write(angle);
  myServo.write(speed);

  //Return angle to 0
  if (angle>ServoState){
    for(angle>=179; ServoState=angle; angle -= 1){
      myServo.write(ServoState);
      delay(speed);
    }
  }
  else{
    myServo.write(0);
  }
  delay(10);
  }
