#include "main.h"

using namespace okapi;

// Chassis Controller - lets us drive the robot around with open- or closed-loop control
void opcontrol() {
  // Joystick to read analog values for tank or arcade control
  // Master controller by default
  Controller controller;

  auto chassis = ChassisControllerFactory::create(
    {20, 13}, {-19, -12},
    AbstractMotor::gearset::green,
    {10_cm, 39.2_cm}
  );
  
  // Arm related objects
  ControllerButton capFlipperUpButton(ControllerDigital::A);
  ControllerButton capFlipperDownButton(ControllerDigital::B);
	ControllerButton intakeInButton(ControllerDigital::R1);
	ControllerButton intakeOutButton(ControllerDigital::R2);

	Motor intakeMotor = 18_rmtr;
  Motor capFlipperMotor = 8_mtr;

  while (true) {
    chassis.tank(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightY));

		if(intakeInButton.isPressed()) {
			intakeMotor.move(-127);
		} else if (intakeOutButton.isPressed()) {
			intakeMotor.move(127);
		} else {
			intakeMotor.move(0);
		}

		if (capFlipperUpButton.isPressed()) {
			intakeMotor.move(-127);
		} else if (capFlipperDownButton.isPressed()) {
			intakeMotor.move(127);
		} else {
			intakeMotor.move(0);
		}

    pros::Task::delay(10);
  }
}
