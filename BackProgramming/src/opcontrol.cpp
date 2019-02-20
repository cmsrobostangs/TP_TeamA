#include "main.h"

using namespace okapi;

Controller *controller;
auto *chassis;
ControllerButton *intakeInButton;
ControllerButton *intakeOutButton;
ControllerButton *capFlipperUpButton;
ControllerButton *capFlipperDownButton;


void opcontrol() {

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
