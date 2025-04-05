#pragma once
#include <vector>
#include "weapon.h"
#include "armor.h"

class Inventory {
    std::vector<Weapon*> weapons;
    std::vector<Armor*> armors;
public:
    Inventory() = default;
    Inventory(const Inventory& other);
    Inventory& operator=(const Inventory& other);
    ~Inventory();

    void addWeapon(Weapon* weapon);
    void addArmor(Armor* armor);
    
    const std::vector<Weapon*>& getWeapons() const;
    const std::vector<Armor*>& getArmors() const;

    friend std::ostream& operator<<(std::ostream& os, const Inventory& inv);
};