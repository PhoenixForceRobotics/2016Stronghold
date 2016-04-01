#include <Commands/Driving/Turning/TurnRightEncoder.h>
#include <RobotMap.h>
#include <Services/Sensor.h>
#include <Services/SensorManager.h>
#include <Subsystems/Drivebase.h>
#include <TuningValues.h>
#include <cmath>

TurnRightEncoder::TurnRightEncoder(double degrees) :
		degrees(degrees) {
	Requires(drivebase);
	initialLeft = 0;
	initialRight = 0;
}

TurnRightEncoder::~TurnRightEncoder() {
}

void TurnRightEncoder::Initialize() {
	initialLeft = SensorManager::getSensorManager()->getSensor(
	SENSOR_DRIVE_BASE_LEFT_ENCODER_ID)->PIDGet();
	initialRight = SensorManager::getSensorManager()->getSensor(
	SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID)->PIDGet();
	double speed = .5;
	drivebase->setLeftSpeed(speed);
	drivebase->setRightSpeed(-speed);
}

void TurnRightEncoder::Execute() {

}

bool TurnRightEncoder::IsFinished() {
	double end = 3000;
	return fabs(
			(fabs(SensorManager::getSensorManager()->getSensor(
			SENSOR_DRIVE_BASE_LEFT_ENCODER_ID)->PIDGet() - initialLeft)
					+ fabs(SensorManager::getSensorManager()->getSensor(
					SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID)->PIDGet() - initialRight))
					/ 2) > end * (degrees / 360.0);
}

void TurnRightEncoder::End() {
	LOG_INFO("TurnDegreeEncoder ENDED!");
	drivebase->setLeftSpeed(0.0);
	drivebase->setRightSpeed(0.0);
}

void TurnRightEncoder::Interrupted() {
	End();
}