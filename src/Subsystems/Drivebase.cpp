#include "Drivebase.h"
#include "../RobotMap.h"

Drivebase::Drivebase() :
		Subsystem("ExampleSubsystem")
{

}

void Drivebase::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Drivebase::setLeftSpeed(double speed) {

}

void Drivebase::setRightSpeed(double speed) {

}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivebase::resetEncoder()
{

}

float Drivebase::getRightDistance(){
	return 0; //TODO change this
}

float Drivebase::getLeftDistance(){
	return 0;
}
