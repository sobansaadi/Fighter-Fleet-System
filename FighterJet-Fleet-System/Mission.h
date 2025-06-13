#ifndef MISSION_H
#define MISSION_H

#include "vector.h"
#include "string.h"
#include <fstream>
using namespace std;

class Mission {
private:
    int missionID;
    Mystring missionName;
    Mystring targetLocation;
    Mystring missionDate;
    Vector<int> assignedjetIDs;
    Vector<int> assignedpilotIDs;

public:
    Mission();
    Mission(int id, const Mystring& name, const Mystring& loc, const Mystring& date);
    int getMissionID() const;
    Mystring getMissionName() const;
    Mystring getLocation() const;
    Mystring getMissionDate() const;
    const Vector<int>& getAssignedjets() const;
    const Vector<int>& getAssignedpilots() const;
    void assignJet(int jetID);
    void assignPilot(int pilotID);
    void saveToFile(ofstream& out) const;
    bool loadFromFile(ifstream& in);
    void display() const;
};

#endif