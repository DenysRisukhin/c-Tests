//
//  Command.h
//  Test2019
//
//  Created by Risukhin Denys on 1/15/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Command_h
#define Command_h

// Pattern turns a request into a standalone object, containing all the information about the request.
// This object can be passed, stored, and executed at different times.

//execute - выполнять

// Command interface
class Command {
public:
    virtual void execute() = 0;
};

// Receiver class
class Light {
public:
    void turnOn() {
        std::cout << "Light is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "Light is OFF" << std::endl;
    }
};

// ConcreteCommand class
class LightOnCommand : public Command {
private:
    // Reference to the receiver
    Light& light;

public:
    LightOnCommand(class Light& l) : light(l) {}

    void execute() override {
        light.turnOn();
    }
};

// Invoker class
class RemoteControl {
private:
    // Command to be executed
    Command* command;

public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void pressButton() {
        command->execute();
    }
};

//int main() {
//    // Client code
//    Light livingRoomLight;
//    LightOnCommand livingRoomLightOn(livingRoomLight);
//
//    RemoteControl remote;
//    remote.setCommand(&livingRoomLightOn);
//
//    // Pressing the button triggers the execution of the command
//    remote.pressButton();
//
//    return 0;
//}

// In this example:
//
// Command is the command interface declaring the execute method.
// LightOnCommand is a concrete command class implementing the Command interface. It encapsulates the action of turning on the light.
// Light is the receiver class that knows how to perform the operation.
// RemoteControl is the invoker class that holds a reference to a command and triggers its execution.
// The Command pattern allows you to decouple the sender (invoker) from the receiver,
// providing a more flexible and extensible design. You can easily add new commands without modifying existing code.

#endif /* Command_h */
