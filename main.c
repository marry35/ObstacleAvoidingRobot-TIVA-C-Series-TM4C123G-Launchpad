#include "motordriver.h"
#include "lcd.h"	                                                                        
#include "sensorDriver.h"
#include "servo.h"

int strDistance = 0;
int leftDistance = 0;
int rightDistance = 0;
int main ()
	
{
	
	//Configuring and Setting up LCD Module
	LCDConfig();
	
	//Configuring and Setting up MotorDriver Modules
	motorDriverConfig();
	
	//Configuring and Setting up Distance Sensor Module
  distanceSensorConfig();
	    
  //Configuring the Servo Motor 
	servoConfig();
	
	
	while(1)
	{
	
		servoNeutral(); //Place Servo Motor in Neutral Position
		strDistance = getDistance(); //Get the straight Distance available
		
		if (strDistance <= 25)
		{
		  Stop();
			Delay (SECOND/2);
			
			//Check again after Some delay if the obstacle is still there
			strDistance = getDistance();
			if (strDistance <= 25)
			{
			  
				//Place the Servo in Right position to take distance value in Right position
				servoRight();
				Delay (SECOND/2);
				rightDistance = getDistance();
				
				//Place the Servo in Left position to take distance value in Right position
				servoLeft();
				Delay(SECOND/2);
				leftDistance = getDistance();
				
				if (leftDistance > rightDistance) //Move in the direction where distance is greater
					moveLeft();
				else
					moveRight();
				
				servoNeutral(); //Again place the servo in Neutral positon to take readings again
				Delay (SECOND/2);
				
				
			}
			
		}
		
		else
			moveForward(); //If there's no obstacle infront then just keep moving forward
	  
		
		
	 
}
	}
