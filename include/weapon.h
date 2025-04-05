#pragma once
#include <string>
#include <ostream>

class Weapon {
    std::string name;
    int damage;
public:
    Weapon(const std::string& name, int damage) : name(name), damage(damage) {}
    int getDamage() const { return damage; }
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << weapon.name << " (Damage: " << weapon.damage << ")";
        return os;
    }
};