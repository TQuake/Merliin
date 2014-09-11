#pragma config(Sensor, S1, , sensorI2CMuxController)
#pragma config(Motor, mtr_S1_C1_1, motorD, tmotorTetrix, openLoop)
#pragma config(Motor, mtr_S1_C1_2, motorE, tmotorTetrix, openLoop, reversed)


#include "JoystickDriver.c"

task main() {
	
	float deadZone = .15;
	float deadZoneLower = .15

While(true) {

	//Redefines the turn ratio each cycle to be a value between -1 and 1 with 0 being the center of the x axis
	float turnRatio = joystick.joy_x2 / 127;

	//checks to see which side of the y axis the joystick is on and lets us go straight more easily with a small deadzone
	//From there it multiplies the opposite motors speed by the turnratio to make it turn the correct direction
	if (turnRatio > deadZone)	{
		motor[MotorE] = -joystick.joy_y2;
		motor[MotorD] = joystick.joy_y2 * turnRatio;
	}

	if (turnRatio < deadZoneLower) {
		motor[MotorE] = -joystick.joy_y2;
		motor[MotorD] = joystick.joy_y2 * turnRatio;
	}

}
}