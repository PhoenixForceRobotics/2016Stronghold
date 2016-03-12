#ifndef TUNING_VALUES_H
#define TUNING_VALUES_H

/**
 * PID ID's
 */
#define PID_ID_SHOOTER_1 0
#define PID_ID_SHOOTER_2 1
#define PID_ID_COLLECTOR 2
#define PID_ID_TURN_DEGREE_RIGHT 3
#define PID_ID_TURN_DEGREE_LEFT 11
#define PID_ID_CAMERA 4
#define PID_ID_ROLLER 5
#define PID_ID_ARM 6
#define PID_ID_WINCH 7
#define PID_ID_DRIVEBASE_LEFT 8
#define PID_ID_DRIVEBASE_RIGHT 9
#define PID_ID_DRIVEBASE_ROT 10

#define LOWB_DISTANCE 1
#define LOWB_SPEED 1
#define LOWB_TURN 1

/**
 * Sensor IDs
 */

#define SENSOR_GYRO_ID 0
#define SENSOR_CAMERA_ID 1
#define SENSOR_DRIVE_BASE_LEFT_ENCODER_ID 2
#define SENSOR_DRIVE_BASE_RIGHT_ENCODER_ID 3
#define SENSOR_COLLECTOR_ROTATION_ENCODER_ID 4
#define SENSOR_COLLECTOR_ROLLER_ENCODER_ID 5
#define SENSOR_SHOOTER_ENCODER_1_ID 6
#define SENSOR_SHOOTER_ENCODER_2_ID 7
#define SENSOR_CLIMBER_WINCH_ENCODER 8
#define SENSOR_CLIMBER_ARM_ENCODER 9

/**
 * Encoder Positions
 */

#define COLLECTOR_ROTATION_ENCODER_TOP_TICKS 0 * COLLECTOR_ROTATION_TICKS_PER_DEGREE
#define COLLECTOR_ROTATION_ENCODER_45_TICKS 70 * COLLECTOR_ROTATION_TICKS_PER_DEGREE
#define COLLECTOR_ROTATION_ENCODER_LOWB_TICKS 120 * COLLECTOR_ROTATION_TICKS_PER_DEGREE
#define COLLECTOR_ROTATION_ENCODER_COLLECT_TICKS 135 * COLLECTOR_ROTATION_TICKS_PER_DEGREE

#define CLIMBER_WINCH_DOWN_POSITION 0
#define CLIMBER_WINCH_UP_POSITION -52500

#define CLIMBER_ARM_DOWN_POSITION 0
//2532
#define CLIMBER_ARM_UP_POSITION 3150

#define REACH_DEFENCE_DISTANCE 420	//TODO: find out this value at practice field
#define REACH_DEFENCE_SPEED .3

#define CLIMBER_SERVO_IN_ANGLE 0
#define CLIMBER_SERVO_OUT_ANGLE 130

/**
 * Power Management
 */
#define POWER_LEVEL_1 12
#define POWER_LEVEL_2 11
#define POWER_LEVEL_3 10

#define POWER_BROWNOUT_VOLTAGE 7
#define POWER_DRIVEBASE_VOLTAGE_WIDTH 0.5
#define POWER_VOLTAGE_WIDTH 1.5

/**
 * PID Values
 */

#define COLLECTOR_ROTATION_P .00015
#define COLLECTOR_ROTATION_I 0
#define COLLECTOR_ROTATION_D 0.000025
#define COLLECTOR_ROTATION_F 0

#define SHOOTER_1_P 0.0075
#define SHOOTER_1_I 0
#define SHOOTER_1_D 0
#define SHOOTER_1_F 0

#define SHOOTER_2_P 0.0075
#define SHOOTER_2_I 0
#define SHOOTER_2_D 0
#define SHOOTER_2_F 0

#define TURN_GYRO_P 0.0075
#define TURN_GYRO_I 0
#define TURN_GYRO_D 0
#define TURN_GYRO_F 0

#define DRIVEBASE_LEFT_P 0.0075
#define DRIVEBASE_LEFT_I 0
#define DRIVEBASE_LEFT_D 0
#define DRIVEBASE_LEFT_F 0

#define DRIVEBASE_RIGHT_P 0.0001
#define DRIVEBASE_RIGHT_I 0
#define DRIVEBASE_RIGHT_D 0
#define DRIVEBASE_RIGHT_F 0

#define DRIVEBASE_ROT_P 0
#define DRIVEBASE_ROT_I 0
#define DRIVEBASE_ROT_D 0
#define DRIVEBASE_ROT_F 0

#define CLIMBER_ARM_P 0.000014
#define CLIMBER_ARM_I 0.000004
#define CLIMBER_ARM_D 0.00005
#define CLIMBER_ARM_F 0

#define CLIMBER_WINCH_P 0.0
#define CLIMBER_WINCH_I 0.0
#define CLIMBER_WINCH_D 0.0
#define CLIMBER_WINCH_F 0.0

#define MOVE_TOWARD_CAMERA_P .3
#define MOVE_TOWARD_CAMERA_I 0
#define MOVE_TOWARD_CAMERA_D 0
#define MOVE_TOWARD_CAMERA_F 0

#endif
