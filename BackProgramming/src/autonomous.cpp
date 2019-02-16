#include "main.h"

using namespace okapi;
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

 auto drive = ChassisControllerFactory::create(
   {20, 13}, {-19, -12},
   AbstractMotor::gearset::green,
   {10_cm, 39.2_cm}
 );

Motor intakeMotor = 18_rmtr;

 void autonomous() {
   intakeMotor.move(-127);
   drive.moveDistance(46_in); // movng forward 39
   pros::Task::delay(100);
   drive.moveDistance(-14_in);
   drive.turnAngle(-90_deg); // turn left 90 degrees or at an right angle
   pros::Task::delay(100);
   drive.moveDistance(16_in); // moving forward 16 inches
   pros::Task::delay(100);
   drive.turnAngle(90_deg);// turn at a left angle
   pros::Task::delay(100);
   drive.moveDistance(22_in); // moving forward the sqare root of 1600 inches
   pros::Task::delay(100);
   drive.moveDistance(-12);
   pros::Task::delay(100);
   drive.turnAngle(90_deg); // turn right
   pros::Task::delay(100);
   intakeMotor.move(0);
   drive.moveDistance(45_in);
   // pros::Task::delay(300);

 }
