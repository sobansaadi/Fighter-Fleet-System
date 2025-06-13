#ifndef FLEET_MANAGER_H
#define FLEET_MANAGER_H

#include "FighterJet.h"
#include "BomberJet.h"
#include "StealthJet.h"
#include "Pilot.h"
#include "Mission.h"
#include "User.h"
#include "JetSimulation.h"
#include "WeaponSystem.h"
#include "string.h"
#include "vector.h"
using namespace std;

class FleetManager {
private:
    static FleetManager* instance;
    Vector<FighterJet*> jets;
    Vector<Pilot> pilots;
    Vector<Mission> missions;
    Vector<User> users;
    Vector<WeaponSystem> weapon;

    FleetManager();
    void loadUsers();
    void loadWeaponSystems();
    void loadJets();
    void loadPilots();
    void loadMissions();
    void loadMaintenanceLogs();

public:
    ~FleetManager();
    static FleetManager* getInstance();

    User getUserbyusername(const Mystring& username) const;
    void addJet(FighterJet* jet);
    void addPilot(const Pilot& pilot);
    void addWeaponSystem(const WeaponSystem& weapon);
    bool createMission(const Mission& mission);
    bool assignJetToMission(int jetID, int missionID);
    bool assignPilotToMission(int pilotID, int missionID);
    bool assignPilotToJet(int pilotID, int jetID);
    void updateJetstatus(int id, const Mystring& status);
    void setPilotAvailability(int id, bool status);
    FighterJet* getJetByID(int id);
    Pilot* getPilotByID(int id);
    Mission* getMissionByID(int id);
    bool authenticateUser(const Mystring& username, const Mystring& password);
    void saveAllData();
    void loadAllData();

    const Vector<FighterJet*>& getJets() const;
    const Vector<Pilot>& getPilots() const;
    const Vector<Mission>& getMissions() const;
    const Vector<User>& getUsers() const;
    const Vector<WeaponSystem>& getWeapon() const;
};

#endif