//
//  5_task_DIP.h
//  Test2019
//
//  Created by Risukhin Denys on 9/15/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef __task_DIP_h
#define __task_DIP_h

#include <iostream>
#include <string>
#include <utility>

// Define the Notification interface
class INotification
{
public:
    virtual void send(const std::string& message) const = 0;
    virtual ~INotification() = default;
};

// Enum for urgency levels
enum class UrgencyLevel
{
    LOW,
    MEDIUM,
    HIGH
};

// Concrete implementation of PushNotification with additional fields
class PushNotification : public INotification
{
public:
    PushNotification(std::string token, std::string title)
        : deviceToken(std::move(token)), title(std::move(title)) {}

    PushNotification(const PushNotification&) = default;
    PushNotification& operator=(const PushNotification&) = default;
    PushNotification(PushNotification&&) noexcept = default;
    PushNotification& operator=(PushNotification&&) noexcept = default;

    void send(const std::string& message) const override
    {
        std::cout << "Sending Push Notification to device " << deviceToken
                  << " with title '" << title << "': " << message << std::endl;
    }

private:
    std::string deviceToken; // Device token for push notifications
    std::string title;       // Title of the notification
};

// Concrete implementation of InAppNotification with additional fields
class InAppNotification : public INotification
{
public:
    InAppNotification(std::string msg, UrgencyLevel level)
        : message(std::move(msg)), urgency(level) {}

    InAppNotification(const InAppNotification&) = default;
    InAppNotification& operator=(const InAppNotification&) = default;
    InAppNotification(InAppNotification&&) noexcept = default;
    InAppNotification& operator=(InAppNotification&&) noexcept = default;

    void send(const std::string& message) const override
    {
        std::string urgencyStr;
        switch (urgency) {
            case UrgencyLevel::LOW:
                urgencyStr = "LOW";
                break;
            case UrgencyLevel::MEDIUM:
                urgencyStr = "MEDIUM";
                break;
            case UrgencyLevel::HIGH:
                urgencyStr = "HIGH";
                break;
        }
        std::cout << "In-App Notification [" << urgencyStr << "]: " << message << std::endl;
    }

private:
    std::string message;      // Message of the notification
    UrgencyLevel urgency;     // Urgency level of the notification
};

// NotificationManager for managing notifications
class NotificationManager
{
public:
    NotificationManager(INotification* notif) : notification(notif) {}
    NotificationManager(const NotificationManager&) = default;
    
    NotificationManager& operator=(const NotificationManager&) = default;
    
    NotificationManager(NotificationManager&& other) noexcept : notification(other.notification) {
        other.notification = nullptr;
    }
    
    NotificationManager& operator=(NotificationManager&& other) noexcept
    {
        if (this != &other)
        {
            notification = other.notification;
            other.notification = nullptr;
        }
        return *this;
    }

    void setNotification(INotification* newNotification)
    {
        notification = newNotification;
    }

    void sendNotification(const std::string& message) const
    {
        if (notification)
        {
            notification->send(message);
        }
    }
    
private:
    INotification* notification;
};

// Main function to demonstrate usage
int main()
{
    PushNotification pushNotif("device_token_123", "New Alert");
    InAppNotification inAppNotif("New message received!", UrgencyLevel::HIGH);

    NotificationManager notifManager1(&pushNotif);

    notifManager1.sendNotification("This is a push notification.");

    NotificationManager notifManager2(std::move(notifManager1));
    notifManager2.setNotification(&inAppNotif);
    notifManager2.sendNotification("This is an in-app notification.");

    NotificationManager notifManager3 = std::move(notifManager2);
    notifManager3.sendNotification("Another in-app notification after move.");

    return 0;
}

//Key Points
//1. Interface Definition: INotification defines the contract for sending notifications.
//2. Concrete Implementations:
//    - PushNotification is tailored for push notifications and includes fields for device token and title.
//    - InAppNotification is designed for notifications shown within the app and includes message and urgency level.
//3. Dependency Injection: NotificationManager uses dependency injection and supports move semantics.
//4. Move Semantics: Move constructors and move assignment operators are implemented to handle the transfer of ownership of notification objects.
//5. Testing: The main function demonstrates the usage of different notification implementations, moves of NotificationManager, and various configurations.


#endif /* __task_DIP_h */
