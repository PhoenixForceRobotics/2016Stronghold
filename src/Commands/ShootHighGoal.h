/*
 * ShootHighGoal.h
 *
 *  Created on: Jan 30, 2016
 *      Author: s-4032218
 */
#include <Subsystems/Collector.h>
#include <Subsystems/SensorManager.h>
#include <CommandBase.h>
#ifndef SRC_COMMANDS_SHOOTHIGHGOAL_H_
#define SRC_COMMANDS_SHOOTHIGHGOAL_H_

class ShootHighGoal {
private:
	enum EShootState {
		SHOOT_STATE_AIMING,
		SHOOT_STATE_FIRING,
		SHOOT_STATE_RESETTING
	};
	float rollerSpeed;
	int collectorRotatorSetpoint;
	int collectorRotatorPosition;
	bool kickerActivated;
	EShootState shootState;
	void ExecuteOff();
	void ExecuteAiming();
	void ExecuteFiring();
	void ExecuteResetting();
public:
	ShootHighGoal();
	virtual ~ShootHighGoal();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_SHOOTHIGHGOAL_H_ */
