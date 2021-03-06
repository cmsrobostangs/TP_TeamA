#include "main.h"

using namespace okapi;


Controller controller;
Motor rearLauncherMotor = (11, pros::E_MOTOR_GEARSET_36, false);
Motor frontLauncherMotor = (5, pros::E_MOTOR_GEARSET_36, false);
ADIButton shooterLoadedSwitch('A');
ControllerButton launcherButton(ControllerDigital::L2);

void autoLoad_fn(void* param) {
  while(true){
		while(shooterLoadedSwitch.isPressed()){
			frontLauncherMotor.move(127);
			rearLauncherMotor.move(127);
		  pros::Task::delay(10);
		}
		if(!pros::competition::is_autonomous() && !launcherButton.isPressed()){
			pros::Task::delay(250);
			frontLauncherMotor.move(0);
			rearLauncherMotor.move(0);
			frontLauncherMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
			rearLauncherMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		}
		else if(pros::competition::is_autonomous() && pros::c::task_notify_take(true, TIMEOUT_MAX)){
			frontLauncherMotor.move(0);
			rearLauncherMotor.move(0);
			frontLauncherMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
			rearLauncherMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		}
		else{
			frontLauncherMotor.move(127);
			rearLauncherMotor.move(127);
		}

		pros::Task::delay(10);

	}
}

void on_center_button() {
	if (launcherButton.isPressed()) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello Vex!");
	pros::lcd::register_btn1_cb(on_center_button);
	pros::Task my_task (autoLoad_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "AutoLoad Task");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
