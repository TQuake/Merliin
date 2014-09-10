#pragma config(Sensor, S1, , sensorI2CMuxController)
#pragma config(Motor, mtr_S1_C1_1, motorD, tmotorTetrix, openLoop)
#pragma config(Motor, mtr_S1_C1_2, motorE, tmotorTetrix, openLoop, reversed)


#include "JoystickDriver.c"

task main()
{
	int threshold = 15; /* Int 'threshold' will allow us to ignore low */

	while(true) // Infinite loop:
	{
		getJoystickSettings(joystick);

		if(arcadeControl(joystick.joy1_y2, joystick.joy1_x2, 5) > threshold){ // If the right analog stick's Y-axis readings are either above or below the threshold:
			motor[motorD] = -joystick.joy1_y2; // Motor D is assigned a power level equal to the right analog stick's Y-axis reading.
		}
		else {// Else if the readings are within the threshold:
			motor[motorD] = 0; // Motor D is stopped with a power level of 0.
		}
	};
};
