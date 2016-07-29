#include "WPILib.h"
#include "Parameters.h"

class Robot: public IterativeRobot
{
private:

	RobotDrive *robotDrive;
	Joystick *driveStick;

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
	}

	void TestPeriodic()
	{

	}

public:
	Robot()
	{
		robotDrive = new RobotDrive(leftSideMotorsCh,rightSideMotorsCh);
		driveStick = new Joystick(driveJsCh);
	}

	~Robot()
	{
		delete robotDrive;
		delete driveStick;
	}
};

START_ROBOT_CLASS(Robot)
