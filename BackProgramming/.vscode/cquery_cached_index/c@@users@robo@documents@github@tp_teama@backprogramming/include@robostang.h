#ifndef _ROBOSTANGS_H_
#define _ROBOSTANGS_H_

#include "okapi/api.hpp"

class Robostang {
private:
  Controller controller;
  Motor rearLauncherMotor = (11, pros::E_MOTOR_GEARSET_36, false);
  Motor frontLauncherMotor = (5, pros::E_MOTOR_GEARSET_36, false);
  Motor intakeMotor = (18,pros::E_MOTOR_GEARSET_18, true);
  Motor capFlipperMotor = (8,pros::E_MOTOR_GEARSET_18, false);
  ADIButton shooterLoadedSwitch('A');
  auto chassis = ChassisControllerFactory::create(
    {20, 13}, {-19, -12},
    AbstractMotor::gearset::green,
    {10_cm, 39.2_cm}
  );
  ControllerButton capFlipperUpButton(ControllerDigital::A);
  ControllerButton capFlipperDownButton(ControllerDigital::B);
  ControllerButton intakeInButton(ControllerDigital::R1);
  ControllerButton intakeOutButton(ControllerDigital::R2);
  ControllerButton launcherButton(ControllerDigital::L2);

public:
Controller getController();
Motor getRearLauncherMotor();
Motor getFrontLauncherMotor();
Motor getIntakeMotor();
Motor getCapFlipperMotor();
auto getChassis();
ADIButton getShooterLoadedSwitch();
ControllerButton getCapFlipperUpButton();
ControllerButton getCapFlipperDownButton();
ControllerButton getIntakeInButton();
ControllerButton getIntakeOutButton();
ControllerButton getLauncherButton();


}

#endif
