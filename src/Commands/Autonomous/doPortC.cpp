#include <Commands/Autonomous/AutoBase.h>

AutoBase *AutoBase::doPortC()
{
	AutoBase *cmd = new AutoBase("Autonomous-doPortC");
	//cmd->AddSequential(new myCommand(myCommandParameters));
		//Add commands here
	return cmd;
}




