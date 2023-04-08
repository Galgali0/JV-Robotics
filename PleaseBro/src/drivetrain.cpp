#include "main.h"
#include "okapi/api.hpp" // Include the OkapiLib C++ API header file

using namespace okapi; // Use the OkapiLib namespace for convenience

// Define the motor ports for the six motors
#define MOTOR_PORT_17 17
#define MOTOR_PORT_18 18
#define MOTOR_PORT_19 19
#define MOTOR_PORT_12 12
#define MOTOR_PORT_13 13
#define MOTOR_PORT_14 14

void initialize() {
    // Initialize the OkapiLib controller
    auto chassisController = ChassisControllerFactory::create(
        {MOTOR_PORT_17, MOTOR_PORT_18, MOTOR_PORT_19}, // Left side motor ports
        {MOTOR_PORT_12, MOTOR_PORT_13, MOTOR_PORT_14} // Right side motor ports
    );

    // Set the gearset for the motors to blue
    chassisController->getModel()->setGearing(AbstractMotor::gearset::blue);

    // Set the controller's maximum velocity
    chassisController->setMaxVelocity(100);
}

void opcontrol() {
    // Retrieve the OkapiLib controller instance
    auto chassisController = ChassisControllerFactory::create(
        {MOTOR_PORT_19, MOTOR_PORT_18, MOTOR_PORT_19}, // Left side motor ports
        {MOTOR_PORT_12, MOTOR_PORT_13, MOTOR_PORT_14} // Right side motor ports
    );

    while (true) {
        // Get the joystick values for the left and right side of the tank drive
        int leftJoystick = controller.getAnalog(ControllerAnalog::leftY);
        int rightJoystick = controller.getAnalog(ControllerAnalog::rightY);

        // Set the tank drive controls using the joystick values
        chassisController->getModel()->tank(leftJoystick, rightJoystick);

        pros::delay(20); // Delay to prevent CPU overload
    }
}