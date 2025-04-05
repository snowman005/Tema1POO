#include <bits/stdc++.h>
#include "../include/character.h"
#include "../include/weapon.h"
#include "../include/armor.h"

using namespace std;

string weapons_names[] = {"Sword", "Axe", "Bow", "Staff", "Dagger"};
string armors_names[] = {"Leather Armor", "Chainmail", "Plate Armor", "Robe", "Cloak"};

Weapon* generateRandomWeapon() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> damageDist(40, 60);
    std::uniform_int_distribution<int> nameDist(1, 1000);
    return new Weapon(weapons_names[nameDist(rng) % 5], damageDist(rng));
}

Armor* generateRandomArmor() {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> defenseDist(20, 50);
    std::uniform_int_distribution<int> nameDist(1, 1000);
    return new Armor(armors_names[nameDist(rng) % 5], defenseDist(rng));
}

int main() {
    string name_hero;
    cout << "Enter the name of the hero: ";
    cin >> name_hero;
    cin.ignore(); // Clear the newline character left in the input buffer

    Character hero(name_hero, 150);
    Character dragon("Grigore Dragonul", 200);
    
    hero.addWeaponToInventory(new Weapon("Excalibur", 25));
    hero.addArmorToInventory(new Armor("Dragon Shield", 15));

    dragon.addWeaponToInventory(new Weapon("Dragon Claws", 30));
    dragon.addArmorToInventory(new Armor("Dragon Scales", 20));
 
    cout << "Initial state:\n" << hero << dragon << "----------------\n";

    hero.attack(dragon);
    cout << "After attack:\n" << hero << dragon << "----------------\n";
    assert(hero.getHealth() == 150);

    Character copyHero = hero;
    Character assignedDragon;
    assignedDragon = dragon;
    cout << "Copied characters:\n" << copyHero << assignedDragon << "----------------\n";

    dragon.attack(hero);
    cout << dragon.getName() << " counterattacks:\n" << hero << dragon << "----------------\n";
    assert(hero.getHealth() == 135);

    cout << "All tests passed!\n";

    cout << "\nPress Enter to start the game...\n";
    cin.ignore(); // Wait for the user to press Enter

    hero.addWeaponToInventory(generateRandomWeapon());
    hero.addArmorToInventory(generateRandomArmor());
    
    Weapon* fireBreath = new Weapon("Fire Breath", 40);
    Armor* solziDeDragon = new Armor("Solzi de Dragon", 25);
    
    dragon.addWeaponToInventory(fireBreath);
    dragon.addArmorToInventory(solziDeDragon);

    while (hero.getHealth() > 0 && dragon.getHealth() > 0) {
        hero.attack(dragon);
        cout << hero.getName() << " attacks Dragon:\n" << hero << dragon;

        if (dragon.getHealth() <= 0) {
            std::cout << dragon.getName() << " has been defeated! " << hero.getName() << " wins!\n";
            break;
        }

        this_thread::sleep_for(std::chrono::seconds(2));

        dragon.attack(hero);
        cout << dragon.getName() << " attacks Hero:\n" << hero << dragon;

        if (hero.getHealth() <= 0) {
            cout << hero.getName() << " has been defeated! " << dragon.getName() << " wins!\n";
            break;
        }

        this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}