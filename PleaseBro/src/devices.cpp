#include "devices.hpp"
#include "main.h"
#include "okapi/impl/device/button/adiButton.hpp"

Motor catapult(20, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
Motor intake(11, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
ADIButton limitSwitch ('B', false);
void DevicesControl(void* _) {
    catapult.setBrakeMode(AbstractMotor::brakeMode::hold);
//code for manual catapult
   /* while (true) {
        if (controller.getDigital(ControllerDigital::down)) {
            catapult.moveVoltage(12000);
        } else {
            catapult.moveVoltage(0);
        }
        pros::delay(20);
    }
    */
    //AUTOMATIC CATAPULT 
    while(true){
       if (!limitSwitch.isPressed() || controller.getDigital(ControllerDigital::R2)) {
            catapult.moveVoltage(12000);
        } else {
            // The limit switch is being pressed AND R2 isnt pressed
            catapult.moveVoltage(0);
        }
    }
        pros::delay(20);
    //INTAKE
    while(true){
        if(controller.getDigital(ControllerDigital::L2)){
           intake.moveVoltage(-12000);
         }
        if(controller.getDigital(ControllerDigital::L1)){
        intake.moveVoltage(12000);
         }
    }
}
