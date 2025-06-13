#include "FleetManager.h"
#include <fstream>
#include <iostream>
using namespace std;


FleetManager* FleetManager::instance = nullptr;

FleetManager::FleetManager() {
    loadAllData();
}

FleetManager::~FleetManager() {
    for (auto jet : jets) {
        if (jet) {
            delete jet;
        }
    }
    jets.clear();
}

FleetManager* FleetManager::getInstance() {
    if (!instance) {
        instance = new FleetManager();
    }
    return instance;
}

void FleetManager::addJet(FighterJet* jet) {
    jets.push(jet);
}

void FleetManager::addPilot(const Pilot& pilot) {
    pilots.push(pilot);
}

bool FleetManager::createMission(const Mission& mission) {
    missions.push(mission);
    return true;
}

bool FleetManager::assignJetToMission(int jetID, int missionID) {
    for (auto jet : jets) {
        if (jet->getID() == jetID) {
            for (auto& mission : missions) {
                if (mission.getMissionID() == missionID) {
                    mission.assignJet(jetID);
                    jet->setStatus("Assigned to Mission");
                    return true;
                }
            }
        }
    }
    return false;
}

bool FleetManager::assignPilotToMission(int pilotID, int missionID) {
    for (auto& pilot : pilots) {
        if (pilot.getPilotID() == pilotID) {
            for (auto& mission : missions) {
                if (mission.getMissionID() == missionID) {
                    mission.assignPilot(pilotID);
                    pilot.setAvailability(false);
                    return true;
                }
            }
        }
    }
    return false;
}

bool FleetManager::assignPilotToJet(int pilotID, int jetID) {
    for (auto& pilot : pilots) {
        if (pilot.getPilotID() == pilotID) {
            for (auto jet : jets) {
                if (jet->getID() == jetID) {
                    pilot.assignJet(jetID);
                    return true;
                }
            }
        }
    }
    return false;
}

void FleetManager::updateJetstatus(int id, const Mystring& status) {
    for (auto jet : jets) {
        if (jet->getID() == id) {
            jet->setStatus(status);
            break;
        }
    }
}

void FleetManager::setPilotAvailability(int id, bool status) {
    for (auto& pilot : pilots) {
        if (pilot.getPilotID() == id) {
            pilot.setAvailability(status);
            break;
        }
    }
}

FighterJet* FleetManager::getJetByID(int jetID) {
    for (auto* jet : jets) {
        if (jet && jet->getID() == jetID) {
            return jet;
        }
    }
    return nullptr;
}


Pilot* FleetManager::getPilotByID(int id) {
    for (auto& pilot : pilots) {
        if (pilot.getPilotID() == id) {
            return &pilot;
        }
    }
    return nullptr;
}

Mission* FleetManager::getMissionByID(int id) {
    for (auto& mission : missions) {
        if (mission.getMissionID() == id) {
            return &mission;
        }
    }
    return nullptr;
}

bool FleetManager::authenticateUser(const Mystring& username, const Mystring& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username && user.authenticate(password)) {
            return true;
        }
    }
    return false;
}


void FleetManager::loadWeaponSystems() {
    ifstream weaponFile("weapons.txt");
    if (weaponFile.is_open()) {
        Mystring weaponType;
        int capacity;
        double range;

        while (weaponFile >> weaponType >> capacity >> range) {
            weapon.emplace_back(weaponType, capacity, range);
        }
        weaponFile.close();
    }
    else {
        weapon.emplace_back("Bombs", 20, 5000);
    }
}

void FleetManager::addWeaponSystem(const WeaponSystem& weaponSystem) {
    weapon.push(weaponSystem);
}

const Vector<WeaponSystem>& FleetManager::getWeapon() const {
    return weapon;
}

User FleetManager::getUserbyusername(const Mystring& username) const {
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            return user;
        }
    }
    return User("", "", "");
}

void FleetManager::saveAllData() {
    ofstream userFile("users.txt");
    for (const auto& user : users) {
        userFile << user.getUsername() << " " << user.getPassword() << " " << user.getRole() << "\n";
    }
    userFile.close();


    ofstream jetFile("jets.txt");
    for (const auto jet : jets) {
        jet->saveToFile(jetFile);
    }
    jetFile.close();

    ofstream pilotFile("pilots.txt");
    for (const auto& pilot : pilots) {
        pilotFile << pilot.getPilotID() << " " << pilot.getName() << " " << pilot.getRank() << " " << pilot.getAssignedjetID() << " " << pilot.getAvailability() << "\n";
    }
    pilotFile.close();

    ofstream missionFile("missions.txt");
    for (const auto& mission : missions) {
        mission.saveToFile(missionFile);
    }
    missionFile.close();

    ofstream maintenanceFile("maintenance.txt");
    for (const auto jet : jets) {
        for (const auto& log : jet->getMaintenancelogs()) {
            maintenanceFile << jet->getID() << " " << log.getDate() << " " << log.getTechnician() << " " << log.getDescription() << "\n";
        }
    }
    maintenanceFile.close();

    ofstream weaponFile("weapons.txt");
    for (const auto& weapon : weapon) {
        weaponFile << weapon.getWeapontype() << " " << weapon.getCapacity() << " " << weapon.getRange() << "\n";
    }
    weaponFile.close();
}

void FleetManager::loadAllData() {
    users.clear();
    jets.clear();
    pilots.clear();
    missions.clear();
    weapon.clear();

    loadUsers();
    loadJets();
    loadPilots();
    loadMissions();
    loadMaintenanceLogs();
    loadWeaponSystems();
}


void FleetManager::loadUsers() {
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        Mystring username, password, role;
        while (userFile >> username >> password >> role) {
            users.emplace_back(username, password, role);
        }
        userFile.close();
    }
    else {
        users.emplace_back("manager", "manager", "manager");
        users.emplace_back("Soban", "pass", "pilot");
    }
}

void FleetManager::loadJets() {
    ifstream jetFile("jets.txt");
    if (jetFile.is_open()) {
        Mystring type;
        while (jetFile >> type) {
            if (type == "BOMBER") {
                auto bomber = new BomberJet();
                bomber->loadFromFile(jetFile);
                jets.push(bomber);
            }
            else if (type == "STEALTH") {
                auto stealth = new StealthJet();
                stealth->loadFromFile(jetFile);
                jets.push(stealth);
            }
        }
        jetFile.close();
    }
    else {
        WeaponSystem bomberWeapons("Bombs", 20, 5000);
        jets.push(new BomberJet(1, "B-52", 650, bomberWeapons));
    }
}

void FleetManager::loadPilots() {
    ifstream pilotFile("pilots.txt");
    if (pilotFile.is_open()) {
        int pilotID, assignedJetID;
        Mystring name, rank;
        bool isAvailable;

        while (pilotFile >> pilotID >> name >> rank >> assignedJetID >> isAvailable) {
            pilots.emplace_back(pilotID, name, rank, assignedJetID, isAvailable);
        }
        pilotFile.close();
    }
    else {
        pilots.emplace_back(1, "Soban", "Captain", 1, true);
    }
}

void FleetManager::loadMissions() {
    ifstream missionFile("missions.txt");
    if (missionFile.is_open()) {
        while (true) {
            Mission mission(0, "", "", "");
            if (!mission.loadFromFile(missionFile)) break;
            missions.push(mission);
        }
        missionFile.close();
    }
    else {
        cout << "Failed to open file\n";
    }
}

void FleetManager::loadMaintenanceLogs() {
    ifstream maintenanceFile("maintenance.txt");
    if (maintenanceFile.is_open()) {
        int jetID;
        Mystring date, technician;

        Mystring line;
        while (getline(maintenanceFile, line)) {
            int tokenCount;
            Mystring* tokens = line.Split(' ', tokenCount);
            if (tokenCount < 4) {
                delete[] tokens;
                continue;
            }

            jetID = tokens[0].StrtoInt();
            date = tokens[1];
            technician = tokens[2];

            Mystring description;
            for (int i = 3; i < tokenCount; i++) {
                if (i > 3) description = description + " ";
                description = description + tokens[i];
            }

            FighterJet* jet = getJetByID(jetID);
            if (jet) {
                jet->addMaintenancelog(Maintenance(date, technician, description));
            }

            delete[] tokens;
        }
    }
}

const Vector<FighterJet*>& FleetManager::getJets() const {
    return jets;
}

const Vector<Pilot>& FleetManager::getPilots() const {
    return pilots;
}

const Vector<Mission>& FleetManager::getMissions() const {
    return missions;
}

const Vector<User>& FleetManager::getUsers() const {
    return users;
}
