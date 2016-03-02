#include <Commands/Driving/HoldAgainstTower.h>
#include <Services/Logger.h>
#include <Subsystems/Drivebase.h>
#include <cstdio>
#include <RobotMap.h>

HoldAgainstTower::HoldAgainstTower(float speed) :
		speed(speed) {
	Requires(drivebase);

}

void HoldAgainstTower::Initialize() {
	char str[1024];
	sprintf(str, "HoldAgainstTower Started");
	Logger::getLogger()->log(str, Info);
	drivebase->holdAgainstTower = true;
}

void HoldAgainstTower::Execute() {
	drivebase->setLeftSpeed(speed);
	drivebase->setRightSpeed(speed);
}

bool HoldAgainstTower::IsFinished() {
	char str[1024];
	sprintf(str, "stopHold %u", drivebase->stopHold);
	Logger::getLogger()->log(str, Info);
	return drivebase->stopHold;
}

void HoldAgainstTower::End() {
	/*drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);*/
	char str[1024];
	sprintf(str, "HoldAgainstTower ended");
	Logger::getLogger()->log(str, Info);
}

void HoldAgainstTower::Interrupted() {
	End();
}
