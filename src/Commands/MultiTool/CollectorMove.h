#ifndef CollectorMove_H
#define CollectorMove_H

#include <CommandBase.h>
#include <PIDOutput.h>
#include <PIDSource.h>
#include <Subsystems/Collector.h>
#include <TuningValues.h>
#include <RobotMap.h>

enum CollectorPosition{
	cTOP, cLowBar, cCollect, c45
};

class CollectorMove: public CommandBase
{
private:
	float           target;
	MotorManager *  motorManager;
	SensorManager * sensorManager;
	int test;
public:
	CollectorMove(CollectorPosition pos);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif /* SRC_COMMANDS_TURNDEGREE_H_ */
