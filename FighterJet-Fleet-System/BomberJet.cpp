#include "BomberJet.h"
#include <iostream>
using namespace std;

BomberJet::BomberJet() : FighterJet(0, "", 0.0, WeaponSystem("", 0, 0.0)) {}

BomberJet::BomberJet(int id, const Mystring& model, double speed, const WeaponSystem& weapon) : FighterJet(id, model, speed, weapon) {}

void BomberJet::saveToFile(ofstream& out) const {
    out << "BOMBER ";
    FighterJet::saveToFile(out);
}

void BomberJet::loadFromFile(ifstream& in) {
    FighterJet::loadFromFile(in);
}