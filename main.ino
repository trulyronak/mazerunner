#include <Servo.h>
#include <NewPing.h>
#define TRIGGER_PIN  11
#define ECHO_PIN     3
#define MAX_DISTANCE 200
int leftPower = 91;
int rightPower = 91;
int leftPin = 5;
int rightPin = 6;
int offset = 5;
Servo leftMotor;
Servo rightMotor;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void pause()
{
  rightMotor.write(rightPower); // 90 is neutral
  leftMotor.write(leftPower);
}
void forward(int t)
{
  rightMotor.write(rightPower-10);
  leftMotor.write(leftPower+10+offset); //spins opposite because leftMotor is mirrored
  delay(t);
  pause();
}
void back(int t)
{
  rightMotor.write(rightPower+10);
  leftMotor.write(leftPower-10-offset);
  delay(t);
  pause();
}
void left(int t)
{
  rightMotor.write(rightPower+10);
  leftMotor.write(leftPower+10+offset);
  delay(t);
  pause();
}
void right(int t)
{
  rightMotor.write(rightPower-10);
  leftMotor.write(leftPower-10-offset);
  delay(t);
  pause();
}
void stopDistance(int dist) //takes in inches
{
  rightMotor.write(rightPower-10);
  leftMotor.write(leftPower+10+offset);
  while(sonar.ping_in() > dist)//move forward until 3 inches from the wall
  {
    delay(100);
  }
  pause();
}
void setup()
{
  Serial.begin(115200);
  leftMotor.attach(leftPin);
  leftMotor.write(90);
  rightMotor.attach(rightPin);
  rightMotor.write(90);
  forward(2000);
  left(2000);
  right(2000);
  
}
void loop()
{
}

