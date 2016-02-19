#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#define ROBOT_NAME "VanillaThunder"

#include "TuningValues.h"

#define MOVE_TOWARD_CAMERA_P 1
#define MOVE_TOWARD_CAMERA_I 0
#define MOVE_TOWARD_CAMERA_D 0
#define MOVE_TOWARD_CAMERA_F 0

#define POWER_DISTRIBUTION_PANEL_PORT 0
#define LOGFILE_NAME "/U/robotLog"

#define DIP_CHANNEL_POSITION_START 0
#define DIP_CHANNEL_POSITIONS 3
#define DIP_CHANNEL_POSITION_END 	DIP_CHANNEL_POSITION_START 	+ DIP_CHANNEL_POSITIONS
#define DIP_CHANNEL_OBSTACLE_START 	DIP_CHANNEL_POSITION_END
#define DIP_CHANNEL_OBSTACLES 3
#define DIP_CHANNEL_OBSTACLE_END 	DIP_CHANNEL_OBSTACLE_START 	+ DIP_CHANNEL_OBSTACLES
#define DIP_CHANNEL_GOAL_START 		DIP_CHANNEL_OBSTACLE_END
#define DIP_CHANNEL_GOALS 1
#define DIP_CHANNEL_GOAL_END 		DIP_CHANNEL_GOAL_START 		+ DIP_CHANNEL_GOALS

#define DIP_START DIP_CHANNEL_POSITION_START
#define DIP_END   DIP_CHANNEL_GOAL_END

/**
 * OI
 */

#define OI_JOYSTICK_LEFT_PORT 0
#define OI_JOYSTICK_RIGHT_PORT 1
#define OI_OPERATOR_PORT 2

/**
 * DriveBase
 */

#define DRIVEBASE_LEFTMOTOR_1_PORT 0
#define DRIVEBASE_LEFTMOTOR_2_PORT 1
#define DRIVEBASE_LEFTMOTOR_3_PORT 2

#define DRIVEBASE_RIGHTMOTOR_1_PORT 13
#define DRIVEBASE_RIGHTMOTOR_2_PORT 14
#define DRIVEBASE_RIGHTMOTOR_3_PORT 15

#define DRIVEBASE_RIGHT_ENCODER_PORT 0
#define DRIVEBASE_LEFT_ENCODER_PORT 4

/**
 * Collector
 */

#define COLLECTOR_ROTATOR_MOTOR_1_PORT 0
#define COLLECTOR_ROTATOR_MOTOR_2_PORT 1

#define COLLECTOR_ROLLER_MOTOR_1_PORT 2

#define COLLECTOR_ROLLER_ENCODER_PORT 19

#define COLLECTOR_KICKER_MOTOR_PORT 4
#define COLLECTOR_ENCODER_TICKS_TO_ANGLE 1


/**
 * Climber
 */

#define CLIMBER_WINCH_MOTOR_1_PORT 6
#define CLIMBER_WINCH_MOTOR_2_PORT 7
#define CLIMBER_WINCH_MOTOR_3_PORT 8
#define CLIMBER_WINCH_MOTOR_4_PORT 9

#define CLIMBER_WINCH_ENCODER_PORT -1

#define CLIMBER_ARM_MOTOR_PORT 10

/**
 * Shooter
 */

#define SHOOTER_MOTOR_1_PORT 14
#define SHOOTER_MOTOR_2_PORT 15

#define SHOOTER_1_ENCODER_PORT 15
#define SHOOTER_2_ENCODER_PORT 16


/**
 * OI Ports
 */

/**
 * Breach Buttons
 */

#define OI_PORTCULLIS_BREACH_PORT 0
#define OI_BUTTON_BREACH_PORT 2
#define OI_CHEVAL_BREACH_PORT 1
#define OI_GENERAL_BREACH_PORT 3

/**
 * Collecting Buttons
 */

#define POWER_BROWNOUT_VOLTAGE 7
#define POWER_DRIVEBASE_VOLTAGE_WIDTH 0.5
#define POWER_VOLTAGE_WIDTH 1.5

#define OI_COLLECT_BALL_PORT 4
#define OI_COLLECTOR_UP_PORT 5

/*
 * Aiming Buttons
 */
#define OI_AIM_AT_GOAL_PORT 6

/**
 * Shooting Buttons
 */
#define OI_SHOOT_LOW_PORT 7
#define OI_SHOOT_HIGH_PORT 8
#define OI_SPIN_UP_SHOOTER_PORT 9

/**
 * Climbing Buttons
 */
#define OI_ROTATE_ARM_PORT 10
#define OI_ENGAGE_WINCH_PORT 11

//auto constants

#define LOGFILE_NAME "/U/robotLog"

#define CHEVAL_ENCODER_TICKS 0
#define MOAT_ENCODER_TICKS 0
#define ROCKWALL_ENCODER_TICKS 0
#define RAMPART_ENCODER_TICKS 0
#define ROUGHTERRAIN_ENCODER_TICKS 0
#define PORTCULLIS_ENCODER_TICKS 0
#define SALLYPORT_ENCODER_TICKS 0
#define LOWBAR_ENCODER_TICKS 0

#define CHEVAL_SPEED 1
#define MOAT_SPEED 1
#define ROCKWALL_SPEED 1
#define RAMPART_SPEED 1
#define ROUGHTERRAIN_SPEED 1
#define PORTCULLIS_SPEED 1
#define SALLYPORT_SPEED 1
#define LOWBAR_SPEED 1

#define MOTOR_DIAMETER 8
#define TICKS_REVOLUTION 360

#endif
