#include "WPILib.h"
#include "Parameters.h"

class Robot: public IterativeRobot
{
private:

	RobotDrive *robotDrive;
	Joystick *driveStick;

	bool isPrimed; //ready to fire
	bool firing; //is the robot firing?

	void RobotInit()
	{

	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		robotDrive->ArcadeDrive(driveStick, Joystick::kYAxis, driveStick, Joystick::kZAxis, true);

		if(driveStick->GetRawButton(jsTriggerButton)
				&& driveStick->GetRawButton(jsFailsafeButton)
				&& isPrimed) { //Only fires once per initialization

			isPrimed = false;
			firing = true;
		}

		if (firing) {
			//TODO launch and shoot periodic
		}
	}

	void TestPeriodic()
	{

	}

public:
	Robot()
	{
		robotDrive = new RobotDrive(leftSideMotorsCh,rightSideMotorsCh);
		driveStick = new Joystick(driveJsCh);

		isPrimed = true;
		firing = false;
	}

	~Robot()
	{
		delete robotDrive;
		delete driveStick;
	}
};

START_ROBOT_CLASS(Robot)
