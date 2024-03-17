#pragma once
#ifndef UNTITLED2_SPACESHIP_H
#define UNTITLED2_SPACESHIP_H
#include <iostream>


class Spaceship {
public:
    Spaceship() = default;
    Spaceship(int _flee, float _damageMultiplier) : flee_posibility{ _flee }, damageMultiplier{ _damageMultiplier } {};

    inline float getHp() const {
        return Hp;
    }
    inline int getFuel() const {
        return fuel;
    }
    inline int getCash() const {
        return cash;
    }
    inline void setHp(float _newHp) {
        Hp = _newHp;
    }
    inline void setFuel(int _newFuel) {
        fuel = _newFuel;
    }
    inline void setCash(int _newCash) {
        cash = _newCash;
    }
    inline float getDamageMultiplier() const {
        return damageMultiplier;
    }
    inline int getEscapePossibility() const {
        return flee_posibility;
    }
    virtual void status() = 0;


protected:
    float Hp{ 100 };
    int fuel{ 100 };
    int cash{ 0 };
    float damageMultiplier{ 0 };
    int flee_posibility{ 0 };
};


class FastShip : public Spaceship {
public:
    FastShip(int _flee, float _damageMultiplier) : Spaceship(_flee, _damageMultiplier) {};

    void status() {
        std::cout << "Hp: " << getHp() << "\nFuel: " << getFuel() << "\nCash: " << getCash() << std::endl;
    }
};

class PowerfulShip : public Spaceship {
public:
    PowerfulShip(int _flee, float _damageMultiplier) : Spaceship(_flee, _damageMultiplier) {};

    void status() {
        std::cout << "Hp: " << getHp() << "\nFuel: " << getFuel() << "\nCash: " << getCash() << std::endl;
    }
};

class BalancedShip : public Spaceship {
public:
    BalancedShip(int _flee, float _damageMultiplier) : Spaceship(_flee, _damageMultiplier) {};

    void status() {
        std::cout << "Hp: " << getHp() << "\nFuel: " << getFuel() << "\nCash: " << getCash() << std::endl;
    }
};
#endif //UNTITLED2_SPACESHIP_H
