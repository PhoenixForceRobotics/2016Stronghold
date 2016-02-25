#include <Commands/Driving/TankDrive.h>
#include <OI.h>
#include <Subsystems/Drivebase.h>

TankDrive::TankDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivebase);
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {
	drivebase->holdAgainstTower = false;
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	if (!drivebase->holdAgainstTower) {
		drivebase->setLeftSpeed(oi->getLeftStickY());
		drivebase->setRightSpeed(oi->getRightStickY());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDrive::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {
	End();
}
