#include "Pilot.h"
#include<iostream>
using namespace std;

Pilot::Pilot() : pilotID(0), name(""), rank(""), assignedjetID(-1), isAvailable(true) {}

Pilot::Pilot(int pilotID, const Mystring& name, const Mystring& rank, int assignedjetID, bool isAvailable) : pilotID(pilotID), name(name), rank(rank),assignedjetID(assignedjetID), isAvailable(isAvailable) {}

void Pilot::displayInfo() const {
    cout << "Pilot ID: " << pilotID << "\n" << "Name: " << name << "\n"<< "Rank: " << rank << "\n";
}

int Pilot::getPilotID() const {
    return pilotID;
}

Mystring Pilot::getName() const {
    return name;
}

Mystring Pilot::getRank() const {
    return rank;
}

int Pilot::getAssignedjetID() const {
    return assignedjetID;
}

bool Pilot::getAvailability() const {
    return isAvailable;
}

void Pilot::assignJet(int jetID) {
    assignedjetID = jetID;
}

void Pilot::setAvailability(bool available) {
    isAvailable = available;
}