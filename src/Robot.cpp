#include <Commands/Autonomous/AutoBase.h>
#include <Commands/Driving/Turning/ArcTurn.h>
#include <Commands/Power/StallProtection.h>
#include <Commands/Scheduler.h>
#include <Robot.h>
#include <RobotBase.h>
#include <RobotMap.h>
#include <Services/MotorManager.h>
#include <Services/SensorManager.h>
#include <Subsystems/Drivebase.h>
#include <TuningValues.h>
#include <Utility.h>
#include <cstdbool>

void Robot::RobotInit() {
	LOG_INFO("START OF NEW RUN \t START OF NEW RUN");
	LOG_INFO("RobotInit Called");
	motorManager = MotorManager::getMotorManager();
	sensorManager = SensorManager::getSensorManager();
	MotorManager::getMotorManager()->initPIDS();

	CommandBase::init();

	//SensorManager::getSensorManager()->initGyro();

	//managePower = new ManagePower();
	//managePower->Start();

	StallProtection *stall = new StallProtection();
	stall->Start();

	//cmd = AutoBase::doLowBarandScore();
	LOG_INFO("END OF ROBOTINIT");
}

void Robot::DisabledInit() {
	Scheduler::GetInstance()->RemoveAll();
	MotorManager::getMotorManager()->disablePID(PID_ID_ARM);
	MotorManager::getMotorManager()->disablePID(PID_ID_COLLECTOR);
	MotorManager::getMotorManager()->disablePID(PID_ID_DRIVEBASE_ROT);
	//MotorManager::getMotorManager()->disablePID(PID_ID_TURN_DEGREE_RIGHT);
}

void Robot::DisabledPeriodic() {
}

void Robot::AutonomousInit() {
	CommandBase::drivebase->setDriverControl(false);
	Scheduler::GetInstance()->RemoveAll();
	LOG_INFO("AutonomousInit Called");
	//turnDegree->Start();
	SensorManager::getSensorManager()->ZeroYaw();
	AutoBase::readValues();
	cmd = AutoBase::getSelectedAuto();
	//cmd = AutoBase::doRoughT();
	//turnDegree = new DriveForwardStraight(5, .25);
	//turnDegree->Start();
	//ArcTurn *turnDegree;
	//turnDegree = new ArcTurn(-60.0, -0.75, .3);
	//turnDegree->Start();
	cmd->Start();
	//RotateTowardCameraTarget *rotate = new RotateTowardCameraTarget();
	//rotate->Start();

	oldTime = GetFPGATime();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	//LOG_INFO("Autonomous TimeDiff = %ud", GetFPGATime() - oldTime);

	oldTime = GetFPGATime();

	//CommandBase::shooter->setShooterSpeed(1.0);
	//CommandBase::shooter->setRightShooterSpeed(.3);

	/*double left = SensorManager::getSensorManager()->getSensor(
	 SENSOR_DRIVE_BASE_LEFT_ENCODER_ID)->PIDGet();
	 double right = SensorManager::getSensorManager()->getSensor(
	 SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID)->PIDGet();

	 LOG_DEBUG("LeftEncoder %f, RightEncoder %f", left, right);*/

	//SmartDashboard::PutNumber("AbsoluteRollerEncoder", Sensor);
}

void Robot::TeleopInit() {
	CommandBase::drivebase->setDriverControl(true);
	Scheduler::GetInstance()->RemoveAll();
	LOG_INFO("TeleOp Called");
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot);

