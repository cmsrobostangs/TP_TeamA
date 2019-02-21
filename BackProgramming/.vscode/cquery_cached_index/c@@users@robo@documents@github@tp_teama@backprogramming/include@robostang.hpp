extern std::shared_ptr<Controller> controller;
extern std::shared_ptr<auto> chassis = ChassisControllerFactory::create(
  {20, 13}, {-19, -12},
  AbstractMotor::gearset::green,
  {10_cm, 39.2_cm}
);
extern std::shared_ptr<Motor> rearLauncherMotor (11, pros::E_MOTOR_GEARSET_36, false);
extern std::shared_ptr<Motor> frontLauncherMotor (5, pros::E_MOTOR_GEARSET_36, false);
extern std::shared_ptr<Motor> intakeMotor (18,pros::E_MOTOR_GEARSET_18, true);
extern std::shared_ptr<Motor> capFlipperMotor (8,pros::E_MOTOR_GEARSET_18, false);
extern std::shared_ptr<ADIButton> shooterLoadedSwitch('A');
extern std::shared_ptr<ControllerButton> launcherButton(ControllerDigital::L2);
extern std::shared_ptr<ControllerButton> capFlipperUpButton(ControllerDigital::A);
extern std::shared_ptr<ControllerButton> capFlipperDownButton(ControllerDigital::B);
extern std::shared_ptr<ControllerButton> intakeInButton(ControllerDigital::R1);
extern std::shared_ptr<ControllerButton> intakeOutButton(ControllerDigital::R2);
extern std::shared_ptr<ControllerButton> launcherButton(ControllerDigital::L2);
