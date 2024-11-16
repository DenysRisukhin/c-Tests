//
//  Serialization.h
//  Test2019
//
//  Created by Risukhin Denys on 4/1/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Serialization_h
#define Serialization_h

//We define a Serializable interface with pure virtual functions serialize and deserialize.
//We define a Player struct that represents a player with a name and a score, which inherits from Serializable<Player>.
//We provide implementations of serialize and deserialize functions for the Player struct.
//We define template functions serialize and deserialize that can serialize and deserialize any object that implements the Serializable interface.
//In the main function, we create a Player object, serialize it to a file named "player.dat", then deserialize it back into another Player object, and finally print the deserialized player's data.
//This example demonstrates a basic template-based approach to serialization and deserialization in C++, which can be extended and customized based on specific requirements in a game development context.

// Serializable interface
template <typename T>
struct Serializable
{
    virtual void serialize(std::ostream& os) const = 0;
    virtual void deserialize(std::istream& is) = 0;
};

// Example class to serialize/deserialize
struct Player : public Serializable<Player>
{
    std::string name;
    int score;

    // Serialize the object
    void serialize(std::ostream& os) const override
    {
        os << name << " " << score << std::endl;
    }

    // Deserialize the object
    void deserialize(std::istream& is) override
    {
        is >> name >> score;
    }
};

// Serialization function
template <typename T>
void serialize(const T& obj, const std::string& filename)
{
    std::ofstream ofs(filename, std::ios::binary);
    obj.serialize(ofs);
}

// Deserialization function
template <typename T>
void deserialize(T& obj, const std::string& filename)
{
    std::ifstream ifs(filename, std::ios::binary);
    obj.deserialize(ifs);
}

//int main()
//{
//    // Example usage
//       Player player1;
//       player1.name = "Alice";
//       player1.score = 100;
//
//       // Serialize the player object
//       serialize(player1, "player.dat");
//
//       // Deserialize the player object
//       Player player2;
//       deserialize(player2, "player.dat");
//
//       // Print deserialized player data
//       std::cout << "Deserialized player: " << player2.name << ", Score: " << player2.score << std::endl;
//
//    return 0;
//}


#endif /* Serialization_h */
