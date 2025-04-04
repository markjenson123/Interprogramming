//Markjenson Abel
//BSIT-R

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

class Room;
class Player;

class Entity {
public:
    virtual void describe() = 0; 
};

class Player : public Entity {
private:
    string name;
    int health;

public:
    Player(string playerName) : name(playerName), health(100) {}

    void describe() override {
        cout << "Player: " << name << ", 100: " << health << endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() {
        return health > 0;
    }
};

class Room : public Entity {
private:
    string description;
    vector<shared_ptr<Room>> connectedRooms;

public:
    Room(string desc) : description(desc) {}

    void describe() override {
        cout << description << endl;
    }

    void connectRoom(shared_ptr<Room> room) {
        connectedRooms.push_back(room);
    }

    void showConnections() {
        cout << "Connected rooms:" << endl;
        for (size_t i = 0; i < connectedRooms.size(); ++i) {
            cout << i + 1 << ". " << connectedRooms[i]->description << endl;
        }
    }

    shared_ptr<Room> getRoom(int index) {
        if (index >= 0 && index < connectedRooms.size()) {
            return connectedRooms[index];
        }
        return nullptr;
    }
};

// Main game function
void gameLoop(Player& player, shared_ptr<Room> currentRoom) {
    string command;
    while (player.isAlive()) {
        currentRoom->describe();
        currentRoom->showConnections();

        cout << "15: ";
        cin >> command;

        if (command == "exit") {
            cout << "Thanks for playing!" << endl;
            break;
        }

        int roomIndex;
        try {
            roomIndex = stoi(command) - 1; // Convert input to integer
        } catch (invalid_argument&) {
            cout << "Invalid input! Please enter a number or 'exit'." << endl;
            continue;
        } catch (out_of_range&) {
            cout << "Number is out of range! Please try again." << endl;
            continue;
        }

        shared_ptr<Room> nextRoom = currentRoom->getRoom(roomIndex);
        if (nextRoom) {
            currentRoom = nextRoom;
        } else {
            cout << "Invalid room selection!" << endl;
        }

        // Simulate an enemy encounter
        if (rand() % 5 == 0) { // 20% chance of encountering an enemy
            cout << "You encountered an enemy!" << endl;
            player.takeDamage(20);
            cout << "You took damage! Current health: " << player.isAlive() << endl;
            if (!player.isAlive()) {
                cout << "You have died!" << endl;
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random encounters

    // Create rooms
    auto room1 = make_shared<Room>("Room 1: A dark and spooky room.");
    auto room2 = make_shared<Room>("Room 2: A bright and sunny room.");
    auto room3 = make_shared<Room>("Room 3: A room filled with treasure.");

    // Connect rooms
    room1->connectRoom(room2);
    room1->connectRoom(room3);
    room2->connectRoom(room1);
    room3->connectRoom(room1);

    // Create player
    string playerName;
    cout << "Markjenson: ";
    cin >> playerName;
    Player player(playerName);

    // Start the game loop
    gameLoop(player, room1);

    return 0;
}