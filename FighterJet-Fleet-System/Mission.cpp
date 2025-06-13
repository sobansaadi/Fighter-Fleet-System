#include "Mission.h"
#include <iostream>
using namespace std;

Mission::Mission() : missionID(0), missionName(""), targetLocation(""), missionDate("") {}

Mission::Mission(int id, const Mystring& name, const Mystring& loc, const Mystring& date) : missionID(id), missionName(name), targetLocation(loc), missionDate(date) {}

int Mission::getMissionID() const {
    return missionID;
}

Mystring Mission::getMissionName() const {
    return missionName;
}

Mystring Mission::getLocation() const {
    return targetLocation;
}

Mystring Mission::getMissionDate() const {
    return missionDate;
}

const Vector<int>& Mission::getAssignedjets() const {
    return assignedjetIDs;
}

const Vector<int>& Mission::getAssignedpilots() const {
    return assignedpilotIDs;
}

void Mission::assignJet(int jetID) {
    assignedjetIDs.push(jetID);
}

void Mission::assignPilot(int pilotID) {
    assignedpilotIDs.push(pilotID);
}

void Mission::saveToFile(ofstream& out) const {
    out << missionID << " " << missionName << " " << targetLocation << " " << missionDate << " " << assignedjetIDs.size() << " ";
    for (int jetID : assignedjetIDs) {
        out << jetID << " ";
    }
    out << assignedpilotIDs.size() << " ";
    for (int pilotID : assignedpilotIDs) {
        out << pilotID << " ";
    }
    out << "\n";
}

void Mission::display() const {
    cout << "Mission ID: " << missionID << "\n" << "Name: " << missionName << "\n" << "Target Location: " << targetLocation << "\n" << "Date: " << missionDate << "\n";

    cout << "Assigned Jets: ";
    if (assignedjetIDs.empty()) {
        cout << "None";
    }
    else {
        for (int id : assignedjetIDs) {
            cout << id << " ";
        }
    }
    cout << "\n";

    cout << "Assigned Pilots: ";
    if (assignedpilotIDs.empty()) {
        cout << "None";
    }
    else {
        for (int id : assignedpilotIDs) {
            cout << id << " ";
        }
    }
    cout << "\n";
}

bool Mission::loadFromFile(ifstream& in) {
    int numJets, numPilots;
    if (!(in >> missionID >> missionName >> targetLocation >> missionDate >> numJets)) {
        return false;
    }

    assignedjetIDs.clear();
    for (int i = 0; i < numJets; ++i) {
        int jetID;
        if (!(in >> jetID)) {
            cout << "Can't read jet ID.\n";
            return false;
        }
        assignedjetIDs.push(jetID);
    }

    if (!(in >> numPilots)) {
        cout << "Can't read pilot count.\n";
        return false;
    }

    assignedpilotIDs.clear();
    for (int i = 0; i < numPilots; ++i) {
        int pilotID;
        if (!(in >> pilotID)) {
            cout << "Can't read pilot ID.\n";
            return false;
        }
        assignedpilotIDs.push(pilotID);
    }

    return true;
}


