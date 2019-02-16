#include "main.h"

using namespace okapi;

// Chassis Controller - lets us drive the robot around with open- or closed-loop control
void opcontrol() {
  // Joystick to read analog values for tank or arcade control
  // Master controller by default
  pros::Controller master(pros::E_CONTROLLER_MASTER);

  auto chassis = ChassisControllerFactory::create(
    {20, 13}, {-19, -12},
    AbstractMotor::gearset::green,
    {4_in,14_in}
  );

  // Arm related objects
  ControllerButton capFlipperUpButton(ControllerDigital::A);
  ControllerButton capFlipperDownButton(ControllerDigital::B);
	ControllerButton intakeInButton(ControllerDigital::R1);
	ControllerButton intakeOutButton(ControllerDigital::R2);

	Motor intakeMotor = 18_rmtr;
  Motor capFlipperMotor = 8_mtr;

  while (true) {
    chassis.tank(master.get_analog(ANALOG_LEFT_Y),master.get_analog(ANALOG_RIGHT_Y));

		if (master.get_digital(DIGITAL_R1)) {
			intakeMotor.move_voltage(-127);
		} else if (master.get_digital(DIGITAL_R2)) {
			intakeMotor.move_voltage(127);
		} else {
			intakeMotor.move_voltage(0);
		}

		if (master.get_digital(DIGITAL_A)) {
			intakeMotor.move_voltage(-127);
		} else if (master.get_digital(DIGITAL_B)) {
			intakeMotor.move_voltage(127);
		} else {
			intakeMotor.move_voltage(0);
		}

    pros::Task::delay(10);
  }
}
