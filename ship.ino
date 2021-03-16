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
#define SERVOX        15
#define SERVOY        16
#define MP3_TX        22   // connect to RX of the MP3 player module
#define MP3_RX        23
#define GREENLIGHTS   27 
#define RADAR         28

// Define the servos
Servo servoX;
Servo servoY;

// Setup serial comms to the MP3 hardware
MP3 mp3(MP3_RX, MP3_TX);

// Get some base counters in for the runtime in seconds.
unsigned int    TickCounter=0;

#define RUN_FREQ 100

// Timings and things to change
#define TIM_SAMPLESTART       5*RUN_FREQ        // 5 seconds
#define TIM_SAMPLELENGTH      61*RUN_FREQ       // 61 seconds

#define TIM_REPEAT            90*RUN_FREQ       // Rewind at 90 seconds (max. value is 655535 = 327 seconds = a little over 5 minutes)

// This runs only once when powering on
void setup()
{
   digitalWrite(GREENLIGHTS, LOW);     // GREEN lights start OFF
   digitalWrite(RADAR, LOW);		// Radar starts OFF   
	
   // All led groups as OUTPUT
   pinMode (GREENLIGHTS, OUTPUT);
   pinMode (RADAR, OUTPUT);
        
   // Attach servos to pins
   servoX.attach(SERVOX);
   servoY.attach(SERVOY);
		
   // Center the servos
   servoX.write(90);
   servoY.write(90);
		
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
       TickCounter = 0;   // Counts up to a single second, then increase the RunTime
   }
	
   // Time the AUDIO
   if (TickCounter == TIM_SAMPLESTART)
   {
      mp3.playWithVolume(1,26);  // Play the first mp3 on the card at volume 26 (max is 30)
      digitalWrite(RADAR, HIGH); // Sample plays? Then radar switch ON
   }        
   if (TickCounter == TIM_SAMPLESTART+TIM_SAMPLELENGTH)
   {
       mp3.stopPlay(); // Stop playing after the show is over
       digitalWrite(RADAR, LOW); // Sample stops? Then headlights switch OFF
   }
	
   // Just a test for the servos every second
   if (TickCounter == 100)
   {
      servoX.write(45);
   }
   if (TickCounter == 200)
   {
      servoY.write(45);
   }
   if (TickCounter == 300)
   {
      servoX.write(135);
   }
   if (TickCounter == 400)
   {
      servoY.write(135);
   }
   if (TickCounter == 500)
   {
      servoX.write(90);
      servoY.write(90);
   }

   delay(1); // Added this dummy delay() to make sure the code takes more than 1 ms to execute.
}
