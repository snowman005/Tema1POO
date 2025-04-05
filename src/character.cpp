#include "../include/character.h"
#include "../include/weapon.h"
#include "../include/armor.h"

Character::Character(const std::string& name, int health) 
    : name(name), health(health) {}

Character::Character(const Character& other) 
    : name(other.name), health(other.health), inventory(other.inventory) {}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        health = other.health;
        inventory = other.inventory;
    }
    return *this;
}

Character::~Character() = default;

void Character::attack(Character& target) {
    int totalDamage = 0;
    for (const auto& weapon : inventory.getWeapons()) {
        if (weapon) {
            totalDamage += weapon->getDamage();
        }
    }
    target.takeDamage(totalDamage);
}

void Character::takeDamage(int damage) {
    int totalDefense = 0;
    for (const auto& armor : inventory.getArmors()) {
        if (armor) {
            totalDefense += armor->getDefense();
        }
    }
    int netDamage = std::max(0, damage - totalDefense);
    health -= netDamage;
    if (health < 0) health = 0; 
}

int Character::getHealth() const {
    return health;
}

std::string Character::getName() const {
    return name;
}

const Inventory& Character::getInventory() const {
    return inventory;
}

// New methods to add items to the inventory
void Character::addWeaponToInventory(Weapon* weapon) {
    inventory.addWeapon(weapon);
}

void Character::addArmorToInventory(Armor* armor) {
    inventory.addArmor(armor);
}

std::ostream& operator<<(std::ostream& os, const Character& character) {
    os << "----------------\n";
    os << "Character: " << character.getName() << "\nHealth: " << character.getHealth() << "\n";
    os << character.inventory;
    os << "----------------\n";
    return os;
}
