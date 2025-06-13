#include "FighterJet.h"
#include <iostream>
using namespace std;

FighterJet::FighterJet(int id, const Mystring& model, double speed, const WeaponSystem& weapon) : id(id), model(model), speed(speed), weapon(weapon), status("Ready") {}

int FighterJet::getID() const {
    return id;
}

Mystring FighterJet::getModel() const {
    return model;
}

double FighterJet::getSpeed() const {
    return speed;
}

WeaponSystem FighterJet::getWeapon() const {
    return weapon;
}

Mystring FighterJet::getStatus() const {
    return status;
}

void FighterJet::performMaintenance(const Mystring& date, const Mystring& tech, const Mystring& desc) {
    maintenancelogs.emplace_back(date, tech, desc);
    status = "Under Maintenance";
}

void FighterJet::saveToFile(ofstream& out) const {
    out << id << " " << model << " " << speed << " " << weapon.getWeapontype() << " " << weapon.getCapacity() << " " << weapon.getRange() << " " << status << "\n";
}

void FighterJet::loadFromFile(ifstream& in) {
    Mystring weaponType;
    int cap;
    double r;

    in >> id >> model >> speed >> weaponType >> cap >> r >> status;
    weapon = WeaponSystem(weaponType, cap, r);
}

void FighterJet::addMaintenancelog(const Maintenance& log) {
    maintenancelogs.push(log);
}

const Vector<Maintenance>& FighterJet::getMaintenancelogs() const {
    return maintenancelogs;
}

void FighterJet::setStatus(const Mystring& status) {
    this->status = status;
}

FighterJet::~FighterJet() {}