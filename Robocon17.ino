/*
ROBOCON'17 (Asian Oceania College robot competition) 
M.I.A Team,Robotics team in the Faculty of Engineering,Alexandria University
Written by : Karim Ahmed Hamdy,Sara El-dawy,Engy,Ahmed Zayton

The objective of the competition is to throw Frisbees(round disks) on diffrent poles with different heights and positions, 
while competing againest another team throwing on the same poles,Winning is calculated by landing the most fresbees on poles.


The system used 3 pneumatic solenoids to conroll the feeding and the throwing mechanisms,2 base motors,
2 brushless motors to give the fresbees the rotating speed,Laser connected to servo motor to calibrate the position towards each pole,
ULN to conrol the solenoids, LCD and joystick to controll the robot. 


*/


#include <PS2X_lib.h>                //Joystick Library
#include <Servo.h>      
#include <LiquidCrystal.h>
#define dir_R_motor 2               //define base motors pins  
#define E_R_motor 3                 //define base motors pins 
#define dir_L_motor 4               //define base motors pins
#define E_L_motor 5                 //define base motors pins
#define dir_fd 12                   //define base motors pins
#define E_fd 13                     //define base motors pins
#define uln_1 16                    //define ULN pins to control the pnuematic solenoids
#define uln_2 17
#define uln_3 18
#define uln_4 19
#define stepp_dir 31                //Define the stepper driver pins
#define stepp_stp 33


LiquidCrystal lcd(A6,A5,A4,A3,A2,A1);// initialize the library with the numbers of the interface pins

Servo esc_forw;                     //Intiating servo class to control the forward brushless motors.
Servo esc_back;                     //Intiating servo class to control the backward brushless motors.
int state= LOW;

PS2X ps2x;                          // create PS2 Controller Class
int error = 0;                      //Booleans to setup the jostick
byte type = 0;
byte vibrate = 0;


double signal1 = 90;                //Initial values for brushless motors
double signal2 = 90;


void setup() {
  Serial.begin(115200);             //beginnning serial communication between the board ans the PC at rate of 115200 bits/sec
  pin_def();
  Error();                          //Checking error for joystick
  esc_forw.write(signal1);          //writing intial values for the brushless motors
  esc_back.write(signal2);
  delay(1000);                      //Wating for stabilization of ESC
  digitalWrite(dir_fd, HIGH);
  digitalWrite(E_fd,state);
}
void loop() { 
  main();

}
