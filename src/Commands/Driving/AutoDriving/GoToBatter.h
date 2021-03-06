#ifndef GoToBatter_H
#define GoToBatter_H

#include <CommandBase.h>
#include <Commands/Autonomous/AutoBase.h>
#include <stddef.h>
#include <cstdbool>

class PIDWrapper;

class CameraReader;

enum BatterState {
	Startup, JustNowFound, MovingAdjacent, TurningToAdjacent, TurningAwayFromAdjacent, JustNowLost, SearchingLeft, SearchingRight, MovingToward, AtBatter
};

class GoToBatter: public CommandBase {
private:
	CameraReader *reader = NULL;
	MotorManager *manager = NULL;
	SensorManager *sensor = NULL;
	BatterState state = Startup;
	eStartPos startPos;
	double adjacentInitialLeft = 0;
	double adjacentInitialRight = 0;
	double distance_adjacent = 0;
	double adjacentInitialYaw = 0;
	PIDWrapper *pid = NULL;
	bool first = false;
	void changeState(BatterState state);
public:
	GoToBatter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
