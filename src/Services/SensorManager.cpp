#include <CANTalon.h>
#include <I2C.h>
#include <Services/CameraReader.h>
#include <Services/MotorManager.h>
#include <Services/SensorManager.h>
#include <TuningValues.h>
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>
#include <utility>

#include "../../navx-mxp/cpp/include/AHRS.h"

Sensor::Sensor(unsigned CANTalonEncoderPort) {
	this->talon = MotorManager::getMotorManager()->getMotor(CANTalonEncoderPort)->talon;
	this->src = NULL;
}

Sensor::Sensor(PIDSource *src) {
	this->talon = NULL;
	this->src = src;
}

Sensor::Sensor(CANTalon *canTalon) {
	this->talon = canTalon;
	this->src = NULL;
}

double Sensor::PIDGet() {
	if (talon != NULL) {
		return talon->PIDGet();
	} else {
		return 0.0;
	}
}

SensorManager::SensorManager() {
	sensors.insert(std::pair<int, Sensor*>(SENSOR_GYRO_ID, new Sensor(ahrs)));
	sensors.insert(std::pair<int, Sensor*>(SENSOR_CAMERA_ID, new Sensor(CameraReader::getCameraReader())));
	sensors.insert(std::pair<int, Sensor*>(SENSOR_DRIVE_BASE_LEFT_ENCODER_ID, new Sensor(SENSOR_DRIVE_BASE_LEFT_ENCODER_ID)));
	sensors.insert(std::pair<int, Sensor*>(SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID, new Sensor(SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID)));
	sensors.insert(std::pair<int, Sensor*>(SENSOR_COLLECTOR_ROTATION_ENCODER_ID, new Sensor(SENSOR_COLLECTOR_ROTATION_ENCODER_ID)));
	sensors.insert(std::pair<int, Sensor*>(SENSOR_COLLECTOR_ROLLER_ENCODER_ID, new Sensor(SENSOR_COLLECTOR_ROLLER_ENCODER_ID)));
	sensors.insert(std::pair<int, Sensor*>(SENSOR_SHOOTER_ENCODER_1_ID, new Sensor(SENSOR_SHOOTER_ENCODER_1_ID)));
	sensors.insert(std::pair<int, Sensor*>(SENSOR_SHOOTER_ENCODER_2_ID, new Sensor(SENSOR_SHOOTER_ENCODER_2_ID)));

	ahrsDead = false;
	try {
		//ahrs = new AHRS(SPI::Port::kMXP);
		ahrs = new AHRS(I2C::Port::kMXP);
		ahrs->Reset();
		counter = 0;
		while (!ahrs->IsConnected()) {
			printf("AHRS NOT CONNECTED\n");
			counter++;
			if (counter > AHRS_CYCLE_TIMEOUT) {
				std::cout << "AHRS DEAD, DEFAULTING TO ENCODER\n";
				ahrsDead = true;
				break;
			}
		}
		printf("Is the AHRS connected? %s",
				(ahrs->IsConnected() ? "Yes\n" : "no\n"));
	} catch (std::exception * ex) {
		std::string err_string = "Error instantiating navX MXP:  ";
		std::cout << err_string;
		err_string += ex->what();
		std::cout << err_string;
		std::cout << "AHRS DEAD, DEFAULTING TO ENCODER\n";
		ahrsDead = true;
	}
}

SensorManager::~SensorManager() {
	delete ahrs;
}

SensorManager* SensorManager::getSensorManager() {
	static SensorManager *instance;
	if (instance == 0) {
		instance = new SensorManager();
	}
	return instance;

}
float SensorManager::getYaw() {
	return ahrs->GetYaw();
}

float SensorManager::getPitch() {
	return ahrs->GetPitch();
}

float SensorManager::getRoll() {
	return ahrs->GetAngle();
	//return ahrs->GetRoll();
}

float SensorManager::GetAccelX() {

	return ahrs->GetWorldLinearAccelX();

}

float SensorManager::GetAccelY() {
	return ahrs->GetWorldLinearAccelY();

}

float SensorManager::GetAccelZ() {
	return ahrs->GetWorldLinearAccelZ();

}

double SensorManager::GetEncoderPosition(int ID) {
	return MotorManager::getMotorManager()->GetPosition(ID);

}
double SensorManager::GetSpeed(int ID) {

	return MotorManager::getMotorManager()->GetSpeed(ID);
}

Sensor* SensorManager::getSensor(unsigned ID) {
	if (ID >= 0 && ID < sensors.size()) {
		return sensors[ID];
	} else {
		return NULL;
	}
}