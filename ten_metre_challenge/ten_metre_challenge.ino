#include <Servo.h>    //include the servo library
#define servoPin 4
Servo myservo;        // create servo object to control a servo
float steeringAngle;  // variable to store the servo position

#define enA 5   //EnableA command line - should be a PWM pin
#define enB 6   //EnableB command line - should be a PWM pin

//name the motor control pins - replace the CHANGEME with your pin number, digital pins do not need the 'D' prefix whereas analogue pins need the 'A' prefix
#define INa A0  //Channel A direction 
#define INb A1  //Channel A direction 
#define INc A2  //Channel B direction 
#define INd A3  //Channel B direction 

byte speedSetting = 0;  //initial speed = 0

void setup() {
  // put your setup code here, to run once:
  
  myservo.attach(servoPin);  //attach our servo object to pin D4
  //the Servo library takes care of defining the PinMode declaration (libraries/Servo/src/avr/Servo.cpp line 240)

  //configure the motor control pins as outputs
  pinMode(INa, OUTPUT);
  pinMode(INb, OUTPUT);
  pinMode(INc, OUTPUT);
  pinMode(INd, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);   

  //initialise serial communication
  Serial.begin(9600);
  Serial.println("Arduino Nano is Running"); //sanity check

  speedSetting = 255;
  motors(speedSetting, speedSetting); //make a call to the "motors" function and provide it with a value for each of the 2 motors - can be different for each motor - using same value here for expedience
  Serial.print("Motor Speeds: ");
  Serial.println(speedSetting); 
}


void loop() {
  // put your main code here, to run repeatedly:
  turnStraight();
  delay(500);
  goForwards();
  delay (20000);
  stopMotors();
  delay (10000000);
  }
  
void turnStraight()
{
  myservo.write(90);
}

void motors(int leftSpeed, int rightSpeed) {
  //set individual motor speed
  //direction is set separately

  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void goForwards() {
  digitalWrite(INa, HIGH);
  digitalWrite(INb, LOW);
  digitalWrite(INc, HIGH);
  digitalWrite(INd, LOW);
}

//void goBackwards() {
//  digitalWrite(INa, LOW);
//  digitalWrite(INb, HIGH);
//  digitalWrite(INc, LOW);
//  digitalWrite(INd, HIGH);
//}
//
//void goClockwise() {
//  digitalWrite(INa, HIGH);
//  digitalWrite(INb, LOW);
//  digitalWrite(INc, LOW);
//  digitalWrite(INd, HIGH);
//}
//
//void goAntiClockwise() {
//  digitalWrite(INa, LOW);
//  digitalWrite(INb, HIGH);
//  digitalWrite(INc, HIGH);
//  digitalWrite(INd, LOW);
//}
void stopMotors() {
  digitalWrite(INa, LOW);
  digitalWrite(INb, LOW);
  digitalWrite(INc, LOW);
  digitalWrite(INd, LOW);
}
