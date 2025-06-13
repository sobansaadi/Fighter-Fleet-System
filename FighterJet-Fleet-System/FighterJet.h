#ifndef FIGHTER_JET_H
#define FIGHTER_JET_H

#include "WeaponSystem.h"
#include "Maintenance.h"
#include "vector.h"
#include <fstream>
#include "string.h"
using namespace std;

class FighterJet {
protected:
    int id;
    Mystring model;
    double speed;
    WeaponSystem weapon;
    Mystring status;
    Vector<Maintenance> maintenancelogs;

public:
    FighterJet(int id, const Mystring& model, double speed, const WeaponSystem& weapon);
    int getID() const;
    Mystring getModel() const;
    double getSpeed() const;
    WeaponSystem getWeapon() const;
    Mystring getStatus() const;
    void performMaintenance(const Mystring& date, const Mystring& tech, const Mystring& desc);
    virtual void saveToFile(ofstream& out) const;
    virtual void loadFromFile(ifstream& in);
    void addMaintenancelog(const Maintenance& log);
    const Vector<Maintenance>& getMaintenancelogs() const;
    void setStatus(const Mystring& status);
    virtual ~FighterJet();
};

#endif