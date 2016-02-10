#ifndef CollectorMove_H
#define CollectorMove_H

/*#include "../CommandBase.h"
#include "WPILib.h"

class CollectorMove: public CommandBase
{
public:
	CollectorMove();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
*/
#include <Subsystems/Collector.h>
#include <CommandBase.h>
#include <PIDOutput.h>
#include <PIDSource.h>

class CollectorMove: public CommandBase, public PIDOutput, public PIDSource
{
private:
	double degree;
	//double speed; See cpp
	MotorManager * motorManager;
	SensorManager * sensorManager;
	PIDController * pidController;
	int target;
	double initialCollectorPosition;
public:
	CollectorMove(int target);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double P;
	double I;
	double D;
	double PIDGet();
	void PIDWrite(float output);
};





#endif /* SRC_COMMANDS_TURNDEGREE_H_ */
