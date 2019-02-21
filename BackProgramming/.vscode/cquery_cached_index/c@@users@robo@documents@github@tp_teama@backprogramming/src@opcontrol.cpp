#include "main.h"

using namespace okapi;

Controller controller;
auto chassis = ChassisControllerFactory::create(
  {20, 13}, {-19, -12},
  AbstractMotor::gearset::green,
  {10_cm, 39.2_cm}
);
Motor intakeMotor = (18,pros::E_MOTOR_GEARSET_18, true);
Motor capFlipperMotor = (8,pros::E_MOTOR_GEARSET_18, false);
ControllerButton capFlipperUpButton(ControllerDigital::A);
ControllerButton capFlipperDownButton(ControllerDigital::B);
ControllerButton intakeInButton(ControllerDigital::R1);
ControllerButton intakeOutButton(ControllerDigital::R2);

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
