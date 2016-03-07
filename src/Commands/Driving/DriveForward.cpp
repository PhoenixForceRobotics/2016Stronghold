#include <Commands/Driving/DriveForward.h>
#include <RobotMap.h>
#include <Services/Logger.h>
#include <Subsystems/Drivebase.h>
#include <TuningValues.h>
#include <cstdio>
#include <cmath>

DriveForward::DriveForward(float distance, float speed) {
	Requires(drivebase);
	//WHEEL_DIAMETER = 8;					//CHANGE (maybe)
	//ENCODER_TICKS_PER_REVOLUTION = 1000;//CHANGE
	sensorManager = SensorManager::getSensorManager();
	motorManager = MotorManager::getMotorManager();
	this->distance = ((distance / DISTANCE_NUMBER));
	this->speed = speed;
	initialYaw = 0.0;
	initialPosition = 0.0;
	errorOffset = 0.0;
}

DriveForward::~DriveForward() {
}

void DriveForward::Initialize() {

	//initialYaw = sensorManager->getYaw();
	//drivebase->setLeftSpeed(speed);
	//drivebase->setRightSpeed(speed);
	initialLeft = fabs(SensorManager::getSensorManager()->getSensor(
	SENSOR_DRIVE_BASE_LEFT_ENCODER_ID)->PIDGet());
	initialRight = fabs(SensorManager::getSensorManager()->getSensor(
	SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID)->PIDGet());

	char str[1024];
	sprintf(str,
			"DriveForward Initialize Called initialLeft %f initialRight %f ",
			initialLeft, initialRight);
	writeToLogFile(LOGFILE_NAME, str);
}

void DriveForward::Execute() {
	double left = fabs(SensorManager::getSensorManager()->getSensor(
	SENSOR_DRIVE_BASE_LEFT_ENCODER_ID)->PIDGet() - initialLeft);
	double right = fabs(SensorManager::getSensorManager()->getSensor(
	SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID)->PIDGet() - initialRight);

	drivebase->setLeftSpeed(speed);
	drivebase->setRightSpeed(speed);

	char str[1024];
	sprintf(str, "left: %f, right: %f", left, right);
	writeToLogFile(LOGFILE_NAME, str);
}

bool DriveForward::IsFinished() {
	double left = fabs(SensorManager::getSensorManager()->getSensor(
	SENSOR_DRIVE_BASE_LEFT_ENCODER_ID)->PIDGet());
	double right = fabs(SensorManager::getSensorManager()->getSensor(
	SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID)->PIDGet());

	double difference = ((left + right) / 2) - initialPosition;
	char str[1024];
	sprintf(str, "Difference: %f, target: %f", difference, distance);
	writeToLogFile(LOGFILE_NAME, str);
	if (fabs(left - initialLeft) > distance
			|| fabs(right - initialRight) > distance) {
		return true;
	}

	return false;

}

void DriveForward::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);
}

void DriveForward::Interrupted() {
	End();
}
