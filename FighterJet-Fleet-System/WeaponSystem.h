#ifndef WEAPON_SYSTEM_H
#define WEAPON_SYSTEM_H

#include "string.h"
using namespace std;

class WeaponSystem {
private:
    Mystring weaponType;
    int capacity;
    double range;

public:
    WeaponSystem();
    WeaponSystem(const Mystring& type, int cap, double r);
    Mystring getWeapontype() const;
    int getCapacity() const;
    double getRange() const;
};

#endif