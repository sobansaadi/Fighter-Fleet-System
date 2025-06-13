#ifndef BOMBER_JET_H
#define BOMBER_JET_H

#include "FighterJet.h"
#include "string.h"
using namespace std;

class BomberJet : public FighterJet {
public:
    BomberJet();
    BomberJet(int id, const Mystring& model, double speed, const WeaponSystem& weapon);
    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
};

#endif