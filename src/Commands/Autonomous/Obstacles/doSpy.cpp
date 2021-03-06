#include <Commands/Autonomous/AutoBase.h>
#include <Commands/Driving/AutoDriving/DriveForward.h>
#include <Commands/MultiTool/RotateShooter.h>

AutoBase *AutoBase::doSpy()
{
	AutoBase *cmd = new AutoBase("Autonomous-doSpy");
	cmd->AddSequential(new RotateShooter(cCollect));
	cmd->AddSequential(new DriveForward(8, 1.0f));

	return cmd;
}



