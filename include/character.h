#pragma once
#include <string>
#include "inventory.h"

class Character {
    int health;
    std::string name; // Private for encapsulation
    Inventory inventory; // Private for encapsulation

public:
    explicit Character(const std::string& name = "Hero", int health = 100);
    Character(const Character& other); 
    Character& operator=(const Character& other);
    ~Character(); 

    void attack(Character& target);
    void takeDamage(int damage);
    int getHealth() const;
    std::string getName() const; // Getter for name
    const Inventory& getInventory() const; // Getter for inventory (read-only access)

    // New methods to add items to the inventory
    void addWeaponToInventory(Weapon* weapon);
    void addArmorToInventory(Armor* armor);

    friend std::ostream& operator<<(std::ostream& os, const Character& character);
};