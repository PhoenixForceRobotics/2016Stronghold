#include <Commands/Autonomous/AutoBase.h>
#include <Commands/Driving/DriveForward.h>
#include <Commands/Driving/TurnDegree.h>
#include <Services/SensorManager.h>

AutoBase *AutoBase::doMoat()
{
	SensorManager * sensorManager = SensorManager::getSensorManager();
	float initialPosition;
	AutoBase *cmd = new AutoBase("Autonomous-doMoat");
	initialPosition = sensorManager->getYaw();

	cmd->AddSequential(new DriveForward(5, 1));

	float turnAngle = sensorManager->getYaw() - initialPosition;
	cmd->AddSequential(new TurnDegree(turnAngle));

	return cmd;
}
