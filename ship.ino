/*--------------------------------------------------------------------------------------------*/
/* Ship led & servos for turrets.                                                             */
/*                                                                                            */
/* Controls various leds and servos to move the turret                                        */
/*                                                                                            */
/* Versioning:                                                                                */
/* 1.00            Creation.                                                                  */
/*--------------------------------------------------------------------------------------------*/

// Includes
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "RedMP3.h"
#include <Servo.h>

// Define the physical pinout
#define SERVOX        5
#define SERVOY        6
#define MP3_TX        7   // connect to RX of the MP3 player module
#define MP3_RX        8
#define GREENLIGHTS   12 
#define RADAR         3

#define RADAR_SPEED       50  // This value will be used to PWM the output to the radar motor to slow it down.
#define RADAR_STARTSPEED  125 // This value is used for starting the radar motor
#define MOTORDELAY        30  // delay in [ms] for starting the radar motor

// Define the servos
Servo servoX;
Servo servoY;

// Setup serial comms to the MP3 hardware
MP3 mp3(MP3_RX, MP3_TX);

// Get some base counters in for the runtime in seconds.
unsigned int    TickCounter=0;

#define servoXmin 45
#define servoXmax 135
#define servoYmin 45
#define servoYmax 135

#define RUN_FREQ 100
// Timings and things to change
#define TIM_SAMPLESTART       20*RUN_FREQ        // 5 seconds
#define TIM_SAMPLELENGTH      15*RUN_FREQ        // 61 seconds
#define TIM_RADAR_ON          1*RUN_FREQ
#define TIM_RADAR_OFF        100*RUN_FREQ        // 100 if larger than the REPEAT time, so radar should never switch off.
#define TIM_GREEN_ON         20*RUN_FREQ
#define TIM_GREEN_OFF        40*RUN_FREQ
#define TIM_SERVOS_ON        26*RUN_FREQ
#define TIM_SERVOS_OFF       40*RUN_FREQ

#define TIM_REPEAT            90*RUN_FREQ       // Rewind at 90 seconds (max. value is 655535 = 327 seconds = a little over 5 minutes)

// This runs only once when powering on
void setup()
{
   digitalWrite(GREENLIGHTS, LOW);     // GREEN lights start OFF
   digitalWrite(RADAR, LOW);    // Radar starts OFF   
  
   // All led groups as OUTPUT
   pinMode (GREENLIGHTS, OUTPUT);
   pinMode (RADAR, OUTPUT);
        
   // Attach servos to pins
   servoX.attach(SERVOX);
   servoY.attach(SERVOY);
    
   // Center the servos
   servoX.write(90);
   servoY.write(90);

   // Get a random seeding by reading analog pin 0 (leave disconnected!)
   randomSeed(analogRead(0));
   
   TickCounter=0;
}

// This loops forever.
void loop()
{
   while ( (millis() % 10) != 0L ) //Just do nothing until millis()/10 has no remainder --> Run at 100Hz
   {
      asm("nop \n"); // Just do NOP to make sure the compiler doesn't optimize the while() away
   }

   // This code executes 100 times a second
   TickCounter++;
   if (TickCounter > TIM_REPEAT)       
   {
       TickCounter = 0;   // Reset the tick counter when we need to restart the animatronics
   }
  
   // Time the AUDIO
   if (TickCounter == TIM_SAMPLESTART)
   {
      mp3.playWithVolume(1,26);  // Play the first mp3 on the card at volume 26 (max is 30)
   }        
   if (TickCounter == TIM_SAMPLESTART+TIM_SAMPLELENGTH)
   {
       mp3.stopPlay(); // Stop playing after the show is over
   }

   if (TickCounter == TIM_RADAR_ON)
   {
      analogWrite(RADAR, RADAR_STARTSPEED); // Radar switch ON
   }
   if (TickCounter == (TIM_RADAR_ON + MOTORDELAY))
   {
      analogWrite(RADAR, RADAR_SPEED); // Radar switch ON
   } 
   if (TickCounter == TIM_RADAR_OFF)
   {
      analogWrite(RADAR, 0); // Radar switch OFF
   } 
   if (TickCounter == TIM_GREEN_ON)
   {
      digitalWrite(GREENLIGHTS, HIGH); // Green leds switch ON
   } 
   if (TickCounter == TIM_GREEN_OFF)
   {
      digitalWrite(GREENLIGHTS, LOW); // Green leds switch OFF
   } 
  
   // Within this timeframe the servo's are allowed to move each second. X moves on the second, Y moves on every half-a-second
   if ( (TickCounter >= TIM_SERVOS_ON) && (TickCounter <= TIM_SERVOS_OFF) && ((TickCounter %100) ==0) )
   {
      servoX.write((unsigned char)random(servoXmin,servoXmax));
   }
   if ( (TickCounter >= TIM_SERVOS_ON) && (TickCounter <= TIM_SERVOS_OFF) && ((TickCounter %100) ==50) )
   {
      servoY.write((unsigned char)random(servoYmin,servoYmax));
   }

   delay(1); // Added this dummy delay() to make sure the code takes more than 1 ms to execute.
}
