#ifndef SRC_SERVICES_MOTOR_H_
#define SRC_SERVICES_MOTOR_H_

#include <stddef.h>
#include <cstdbool>

class CANTalon;

enum Priority {
	PRIORITY_FIRST,
	PRIORITY_DRIVEBASE = PRIORITY_FIRST,
	PRIORITY_PRIMARY_ACTUATORS,
	PRIORITY_SECONDARY_ACTUATORS,
	PRIORITY_ACCESSORIES,
	PRIORITYS
};

enum ESubsystem {
	DRIVEBASE, WINCH, ARM, COLLECTOR_ROTATOR, ROLLER, SHOOTER
};

class Motor {
	friend class MotorManager;
private:
	bool reversed;
public:
	Motor(Priority prioArg, int portArg, float maxCurrent,
			ESubsystem parentSubsystem, bool reversed);
	~Motor();
	ESubsystem parentSubsystem;
	CANTalon * talon = NULL;
	float speed;
	float maxCurrent;
	long long int overCurrentStartTime;
	long long int stoppedStartTime;
	Priority motorPriority;
	unsigned port;
	float C;
	void setC(Priority priority, float voltage);bool isReversed();
};

#endif /* SRC_SERVICES_MOTOR_H_ */
