#ifndef PILOT_H
#define PILOT_H
using namespace std;

#include "string.h"
#include "vector.h"

class Pilot {
private:
    int pilotID;
    Mystring name;
    Mystring rank;
    int assignedjetID;
    bool isAvailable;

public:
    Pilot();
    Pilot(int pilotID, const Mystring& name, const Mystring& rank, int assignedjetID, bool isAvailable);
    void displayInfo() const;
    int getPilotID() const;
    Mystring getName() const;
    Mystring getRank() const;
    int getAssignedjetID() const;
    bool getAvailability() const;
    void assignJet(int jetID);
    void setAvailability(bool available);
};

#endif