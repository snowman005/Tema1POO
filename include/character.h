#pragma once
#include <string>
#include "inventory.h"

class Character {
  int health;
  public:
    std::string name;
    Inventory inventory;
    explicit Character(const std::string& name = "Hero", int health = 100);
    Character(const Character& other); 
    Character& operator=(const Character& other);
    ~Character(); 
    void attack(Character& target);
    void takeDamage(int damage);
    int getHealth() const;
    friend std::ostream& operator<<(std::ostream& os, const Character& character);
};