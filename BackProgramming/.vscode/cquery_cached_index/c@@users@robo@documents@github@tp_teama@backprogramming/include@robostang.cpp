#include "robostang.h"

Controller Robostang::getController(){
  return controller;
}

Motor Robostang::getFrontLauncherMotor(){
  return frontLauncherMotor;
}

Motor Robostang::getRearLauncherMotor(){
  return rearLauncherMotor;
}

Motor Robostang::getIntakeMotor(){
  return intakeMotor;
}

Motor Robostang::getCapFlipperMotor(){
  return capFlipperMotor;
}

auto Robostang::getChassis(){
  return auto;
}

ADIButton getShooterLoadedSwitch(){
  return shooterLoadedSwitch;
}

ControllerButton getCapFlipperUpButton(){
  return capFlipperUpButton;
}
ControllerButton getCapFlipperDownButton(){
  return capFlipperDownButton;
}
ControllerButton getIntakeInButton(){
  return intakeInButton;
}
ControllerButton getIntakeOutButton(){
  return intakeOutButton;
}
ControllerButton getLauncherButton(){
  return launcherButton;
}
