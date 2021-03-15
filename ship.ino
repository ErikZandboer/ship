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
#include <Servo.h>

// Define the physical pinout
#define GREENLIGHTS   26 
#define SERVOX		  20
#define SERVOY        21

// Define the servos
Servo servoX;
Servo servoY;

// Get some base counters in for the runtime in seconds.
unsigned int    TickCounter=0;

#define RUN_FREQ 100

#define TIM_REPEAT            90*RUN_FREQ       // Rewind at 90 seconds (max. value is 655535 = 327 seconds = a little over 5 minutes)

// This runs only once when powering on
void setup()
{
        digitalWrite(GREENLIGHTS, HIGH);     // GREEN lights start OFF
        
        // All led groups as OUTPUT
        pinMode (GREENLIGHTS, OUTPUT);
        
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
