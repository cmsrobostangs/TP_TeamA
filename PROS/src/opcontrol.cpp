#include "okapi/api.hpp"
using namespace okapi;

// Chassis Controller - lets us drive the robot around with open- or closed-loop control
auto drive = ChassisControllerFactory::create(
  {20, 13}, {-19, -12},
  AbstractMotor::gearset::green,
  {4_in, 10.5_in}
);

void opcontrol() {
  // Joystick to read analog values for tank or arcade control
  // Master controller by default
  Controller controller;

  // Arm related objects
  ControllerButton capFlipperUpButton(ControllerDigital::A);
  ControllerButton capFlipperDownButton(ControllerDigital::B);
	ControllerButton intakeInButton(ControllerDigital::R1);
	ControllerButton intakeOutButton(ControllerDigital::R2);

	Motor intakeMotor = 18_rmtr;
  Motor capFlipperMotor = 8_mtr;

  while (true) {
    // Tank drive with left and right sticks and deadband of 5
    drive.tank(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightY),5);

		if (capFlipperUpButton.isPressed()) {
			intakeMotor.move_voltage(-127);
		} else if (capFlipperDownButton.isPressed()) {
			intakeMotor.move_voltage(127);
		} else {
			intakeMotor.move_voltage(0);
		}

		if (intakeInButton.isPressed()) {
			intakeMotor.move_voltage(-127);
		} else if (intakeOutButton.isPressed()) {
			intakeMotor.move_voltage(127);
		} else {
			intakeMotor.move_voltage(0);
		}

    pros::Task::delay(10);
  }
}
