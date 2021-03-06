/*
 * RunWinch.h
 *
 *  Created on: Feb 21, 2016
 *      Author: S-4020395
 */

#ifndef SRC_COMMANDS_CLIMBING_RUNWINCH_H_
#define SRC_COMMANDS_CLIMBING_RUNWINCH_H_

#include <CommandBase.h>

class RunWinch : public CommandBase{
private:
	float speed;
	int counter = 0;
	float timeout;
	float realspeed = .75;
public:
	RunWinch(float setPoint, float timeout = 0);
	~RunWinch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};



#endif /* SRC_COMMANDS_CLIMBING_RUNWINCH_H_ */
