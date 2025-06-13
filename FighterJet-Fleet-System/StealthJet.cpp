#include "StealthJet.h"
#include <iostream>
using namespace std;

StealthJet::StealthJet() : FighterJet(0, "", 0.0, WeaponSystem("", 0, 0.0)) {}

StealthJet::StealthJet(int id, const Mystring& model, double speed, const WeaponSystem& weapon) : FighterJet(id, model, speed, weapon) {}

void StealthJet::saveToFile(ofstream& out) const {
    out << "STEALTH ";
    FighterJet::saveToFile(out);
}

void StealthJet::loadFromFile(ifstream& in) {
    FighterJet::loadFromFile(in);
}