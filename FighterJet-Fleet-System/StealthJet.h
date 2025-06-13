#ifndef STEALTH_JET_H
#define STEALTH_JET_H

#include "FighterJet.h"
#include "string.h"
using namespace std;

class StealthJet : public FighterJet {
public:
    StealthJet();
    StealthJet(int id, const Mystring& model, double speed, const WeaponSystem& weapon);
    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
};

#endif