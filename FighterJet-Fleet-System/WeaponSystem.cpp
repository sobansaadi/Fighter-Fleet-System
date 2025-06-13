#include "WeaponSystem.h"
using namespace std;

WeaponSystem::WeaponSystem() : weaponType(""), capacity(0), range(0) {}

WeaponSystem::WeaponSystem(const Mystring& type, int cap, double r) : weaponType(type), capacity(cap), range(r) {}

Mystring WeaponSystem::getWeapontype() const {
    return weaponType;
}

int WeaponSystem::getCapacity() const {
    return capacity;
}

double WeaponSystem::getRange() const {
    return range;
}