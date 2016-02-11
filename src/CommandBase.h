#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Commands/Command.h>
#include <Subsystems/SensorManager.h>

class Collector;
class OI;

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class Drivebase;
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static Drivebase *drivebase;
	static Collector *collector;
	static SensorManager *sensorManager;
};

#endif
