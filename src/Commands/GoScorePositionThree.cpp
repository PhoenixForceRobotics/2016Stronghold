#include <Commands/Driving/DriveForwardStraight.h>
#include <Commands/Driving/DriveForwardStraightAccurate.h>
#include <Commands/Driving/DriveTowardsTower.h>
#include <Commands/Driving/Turning/PIDTurn.h>
#include <Commands/GoScorePositionThree.h>
#include <Commands/MultiTool/RotateShooter.h>
#include <Commands/Shooting/AutoRunCollector.h>
#include <Commands/Shooting/PIDShot.h>
#include <Commands/WaitUntilAutoTime.h>
#include <cstdbool>

GoScorePositionThree::GoScorePositionThree() {
	AddSequential(new DriveForwardStraightAccurate(-3.25, -.65, 3.0));
	AddParallel(new RotateShooter(ShooterPosition::cTOP));

	AddSequential(new PIDTurn(90, 3.5));
	AddSequential(new DriveForwardStraightAccurate(-3.0, -.65, 3.0));
	AddSequential(new PIDTurn(0, 3.5));

	AddSequential(new DriveTowardsTower(-.3, .08, .75));
	AddSequential(new DriveTowardsTower(-.3, .06, .75));
	AddParallel(new DriveTowardsTower(-.3, .04));

	const double shot_speed = 75.0;

	AddSequential(new WaitUntilAutoTime(11));
	AddParallel(new RotateShooter(ShooterPosition::cTOP));
	AddParallel(new PIDShot(shot_speed, shot_speed, 10.0));
	AddParallel(new AutoRunCollector(true));
	AddSequential(new DriveForwardStraight(-8.5, -.3));
}
