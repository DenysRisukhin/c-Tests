//
//  1_task_SRP.h
//  Test2019
//
//  Created by Risukhin Denys on 9/15/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef __task_SRP_h
#define __task_SRP_h

#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <stdexcept>

// Class that represents user profile data
class UserProfile
{
public:
    // Explicit constructor to avoid implicit conversions
    explicit UserProfile(const std::string& username, const std::string& email, int age)
        : m_username(username), m_email(email), m_age(age) {}

    // Move constructor
    UserProfile(UserProfile&& other) noexcept
        : m_username(std::move(other.m_username)), m_email(std::move(other.m_email)), m_age(other.m_age) {}

    // Move assignment operator
    UserProfile& operator=(UserProfile&& other) noexcept {
        if (this != &other) {
            m_username = std::move(other.m_username);
            m_email = std::move(other.m_email);
            m_age = other.m_age;
        }
        return *this;
    }

    // Disable copy constructor and copy assignment operator
    UserProfile(const UserProfile&) = delete;
    UserProfile& operator=(const UserProfile&) = delete;

    // Getters
    std::string getUsername() const { return m_username; }
    std::string getEmail() const { return m_email; }
    int getAge() const { return m_age; }

private:
    std::string m_username;
    std::string m_email;
    int m_age;
};

// Class that handles storage of user profiles
class UserProfileStorage {
public:
    // Explicit constructor
    explicit UserProfileStorage(const std::string& filename) : m_filename(filename) {}

    // Method to save user profile
    void saveProfile(const UserProfile& profile) const {
        std::ofstream file(m_filename, std::ios::app);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file for writing.");
        }
        file << profile.getUsername() << "," << profile.getEmail() << "," << profile.getAge() << std::endl;
        file.close();
    }

    // Method to load profiles (simplified for example)
    void loadProfiles() const {
        std::ifstream file(m_filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file for reading.");
        }
        std::string line;
        while (std::getline(file, line)) {
            std::cout << "Loaded profile: " << line << std::endl;
        }
        file.close();
    }

private:
    std::string m_filename;
};

// Class that formats user profile data for display
class UserProfileFormatter {
public:
    // Explicit constructor
    explicit UserProfileFormatter(const UserProfile& profile) : m_profile(profile) {}

    // Method to format profile as a string
    std::string formatProfile() const {
        return "Username: " + m_profile.getUsername() + "\nEmail: " + m_profile.getEmail() + "\nAge: " + std::to_string(m_profile.getAge());
    }

private:
    UserProfile m_profile;
};

int main() {
    try {
        // Create a user profile
        UserProfile profile("john_doe", "john@example.com", 30);

        // Create storage and formatter
        UserProfileStorage storage("user_profiles.txt");
        UserProfileFormatter formatter(profile);

        // Save profile
        storage.saveProfile(profile);

        // Load and display profiles
        storage.loadProfiles();

        // Display formatted profile
        std::cout << formatter.formatProfile() << std::endl;

        // Test move semantics
        UserProfile movedProfile = std::move(profile); // Move constructor in action
        UserProfileFormatter movedFormatter(movedProfile); // Moved profile

        // Display formatted profile
        std::cout << movedFormatter.formatProfile() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}


#endif /* __task_SRP_h */
