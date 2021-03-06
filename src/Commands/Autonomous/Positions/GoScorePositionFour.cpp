#include <Commands/Autonomous/Positions/GoScorePositionFour.h>
#include <Commands/Driving/AutoDriving/DriveForwardStraight.h>
#include <Commands/Driving/AutoDriving/DriveForwardStraightAccurate.h>
#include <Commands/Driving/AutoDriving/DriveTowardsTower.h>
#include <Commands/Driving/Turning/PIDTurn.h>
#include <Commands/MultiTool/RotateShooter.h>
#include <Commands/Shooting/AutoRunCollector.h>
#include <Commands/Shooting/PIDShot.h>
#include <Commands/WaitUntilAutoTime.h>
#include <TuningValues.h>
#include <cstdbool>

GoScorePositionFour::GoScorePositionFour() {
	AddSequential(new DriveForwardStraightAccurate(-3.5, -.65, 3.0, true));
	AddParallel(new RotateShooter(ShooterPosition::cTOP));

	AddSequential(new PIDTurn(-30, true, 3.5));
	AddSequential(new DriveForwardStraight(-2.0, -.5, 3.0));
	AddSequential(new PIDTurn(0, true, 3.5));

	AddParallel(new DriveTowardsTower(-.3, .08));

	const double shot_speed = AUTO_SHOT_SPEED;

	AddSequential(new WaitUntilAutoTime(12.5));
	AddParallel(new RotateShooter(ShooterPosition::cTOP));
	AddParallel(new PIDShot(shot_speed, shot_speed, 10.0));
	AddParallel(new AutoRunCollector(true));
	AddSequential(new DriveForwardStraight(-8.5, -.3));
}
