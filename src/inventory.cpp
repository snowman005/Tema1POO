#include "inventory.h"
#include <iostream>

Inventory::Inventory(const Inventory& other) {
    for (auto w : other.weapons) {
        weapons.push_back(new Weapon(*w));
    }
    for (auto a : other.armors) {
        armors.push_back(new Armor(*a));
    }
}

Inventory& Inventory::operator=(const Inventory& other) {
    if (this != &other) {
        for (auto w : weapons) delete w;
        for (auto a : armors) delete a;
        weapons.clear();
        armors.clear();
        
        for (auto w : other.weapons) {
            weapons.push_back(new Weapon(*w));
        }
        for (auto a : other.armors) {
            armors.push_back(new Armor(*a));
        }
    }
    return *this;
}

Inventory::~Inventory() {
    for (auto w : weapons) delete w;
    for (auto a : armors) delete a;
}

void Inventory::addWeapon(Weapon* weapon) {
    weapons.push_back(new Weapon(*weapon));
}

void Inventory::addArmor(Armor* armor) {
    armors.push_back(new Armor(*armor));
}

const std::vector<Weapon*>& Inventory::getWeapons() const {
    return weapons;
}

const std::vector<Armor*>& Inventory::getArmors() const {
    return armors;
}

std::ostream& operator<<(std::ostream& os, const Inventory& inv) {
    os << "Weapons: \n";
    for (auto w : inv.weapons) {
        os <<"  " << *w << "\n";
    }
    os << "Armors: \n";
    for (auto a : inv.armors) {
        os << "  "<< *a << "\n";
    }
    return os;
}
