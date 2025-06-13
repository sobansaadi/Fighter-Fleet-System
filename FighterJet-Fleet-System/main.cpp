#include "JetSimulation.h"
#include "FleetManager.h"
#include "raylib.h"
#include "string.h"
#include <iostream>
using namespace std;

void runSimulation(FighterJet* jet) {
    if (!jet) {
        cout << "Error! No Jet.\n";
        return;
    }

    const int screenWidth = 800;
    const int screenHeight = 600;
    Mystring a = "Jet Simulation - ";
    InitWindow(screenWidth, screenHeight, (a + jet->getModel()).c_str());
    SetTargetFPS(60);

    JetSimulation simulation;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) simulation.moveForward();
        if (IsKeyDown(KEY_S)) simulation.moveBackward();
        if (IsKeyDown(KEY_A)) simulation.moveLeft();
        if (IsKeyDown(KEY_D)) simulation.moveRight();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0, 0, screenWidth, 100, DARKBLUE);
        DrawLine(0, 100, screenWidth, 100, GREEN);
        DrawText("FIGHTER JET SIMULATION", 20, 10, 28, SKYBLUE);
        DrawText(TextFormat("Model: %s", jet->getModel().c_str()), 20, 45, 20, RAYWHITE);
        DrawText(TextFormat("Status: %s", jet->getStatus().c_str()), 20, 70, 18, LIGHTGRAY);
        DrawText("WASD to Move | ESC to Exit", 570, 75, 16, GRAY);

        simulation.draw();

        EndDrawing();
    }

    CloseWindow();
}


void displayManagerMenu() {
    FleetManager* manager = FleetManager::getInstance();
    int choice;

    do {
        cout << "\nFleet Manager Dashboard\n";
        cout << "1. View All Jets\n";
        cout << "2. View All Pilots\n";
        cout << "3. View All Missions\n";
        cout << "4. Create New Mission\n";
        cout << "5. Assign Jet to Mission\n";
        cout << "6. Assign Pilot to Mission\n";
        cout << "7. Assign Pilot to Jet\n";
        cout << "8. Update Jet Status\n";
        cout << "9. View Maintenance Logs\n";
        cout << "10. Perform Maintenance\n";
        cout << "11. View Weapon Systems\n";
        cout << "12. Add New Pilot\n";
        cout << "13. Add New Jet\n";
        cout << "14. Set Pilot Availability\n";
        cout << "15. View Jet by ID\n";
        cout << "16. View Pilot by ID\n";
        cout << "17. View Mission by ID\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nAll Jets:\n";
            cout << "ID Model Speed WeaponType Status\n";
            for (const auto jet : manager->getJets()) {
                cout << jet->getID() << " " << jet->getModel() << " " << jet->getSpeed() << " " << jet->getWeapon().getWeapontype() << " " << jet->getStatus() << "\n";
            }
            break;
        }
        case 2: {
            cout << "\nAll Pilots:\n";
            cout << "ID   Name   Rank   JetID   Available\n";
            for (const auto& pilot : manager->getPilots()) {
                cout << pilot.getPilotID() << " " << pilot.getName() << " " << pilot.getRank() << " " << pilot.getAssignedjetID() << " " << (pilot.getAvailability() ? "Yes" : "No") << "\n";
            }
            break;
        }
        case 3: {
            const auto& missions = manager->getMissions();
            if (missions.empty()) {
                cout << "No missions found.\n";
            }
            else {
                for (const auto& mission : missions) {
                    mission.display();
                    cout << "--------------------------\n";
                }
            }
            break;
        }

        case 4: {
            int missionID;
            Mystring name, target, date;

            cout << "Enter Mission ID: ";
            cin >> missionID;
            cin.ignore();
            cout << "Enter Mission Name: ";
            getline(cin, name);
            cout << "Enter Target Location: ";
            getline(cin, target);
            cout << "Enter Mission Date: ";
            getline(cin, date);

            if (manager->createMission(Mission(missionID, name, target, date))) {
                cout << "Mission created successfully.\n";
            }
            else {
                cout << "Can't create mission.\n";
            }
            break;
        }
        case 5: {
            int jetID, missionID;
            cout << "Enter Jet ID: ";
            cin >> jetID;
            cout << "Enter Mission ID: ";
            cin >> missionID;

            if (manager->assignJetToMission(jetID, missionID)) {
                cout << "Jet assigned to mission successfully.\n";
            }
            else {
                cout << "Can't assign jet to mission.\n";
            }
            break;
        }
        case 6: {
            int pilotID, missionID;
            cout << "Enter Pilot ID: ";
            cin >> pilotID;
            cout << "Enter Mission ID: ";
            cin >> missionID;

            if (manager->assignPilotToMission(pilotID, missionID)) {
                cout << "Pilot assigned to mission successfully.\n";
            }
            else {
                cout << "Can't assign pilot to mission.\n";
            }
            break;
        }
        case 7: {
            int pilotID, jetID;
            cout << "Enter Pilot ID: ";
            cin >> pilotID;
            cout << "Enter Jet ID: ";
            cin >> jetID;

            if (manager->assignPilotToJet(pilotID, jetID)) {
                cout << "Pilot assigned to jet successfully.\n";
            }
            else {
                cout << "Can't assign pilot to jet.\n";
            }
            break;
        }
        case 8: {
            int jetID;
            Mystring status;
            cout << "Enter Jet ID: ";
            cin >> jetID;
            cout << "Enter New Status: ";
            cin >> status;

            manager->updateJetstatus(jetID, status);
            cout << "Jet status updated.\n";
            break;
        }
        case 9: {
            int jetID;
            cout << "Enter Jet ID to view maintenance logs: ";
            cin >> jetID;

            FighterJet* jet = manager->getJetByID(jetID);
            if (jet) {
                cout << "\nMaintenance Logs:\n";
                for (const auto& log : jet->getMaintenancelogs()) {
                    cout << "Date: " << log.getDate() << ", Technician: " << log.getTechnician() << ", Description: " << log.getDescription() << "\n";
                }
            }
            else {
                cout << "Jet not found.\n";
            }
            break;
        }
        case 10: {
            int jetID;
            Mystring date, tech, desc;
            cout << "Enter Jet ID: ";
            cin >> jetID;
            cin.ignore();
            cout << "Enter Date: ";
            getline(cin, date);
            cout << "Enter Technician Name: ";
            getline(cin, tech);
            cout << "Enter Description: ";
            getline(cin, desc);

            FighterJet* jet = manager->getJetByID(jetID);
            if (jet) {
                jet->performMaintenance(date, tech, desc);
                cout << "Maintenance logged successfully.\n";
            }
            else {
                cout << "Jet not found.\n";
            }
            break;
        }
        case 11: {
            cout << "\nAll Weapon Systems:\n";
            cout << "Type   Capacity   Range\n";
            for (const auto& weapon : manager->getWeapon()) {
                cout << weapon.getWeapontype() << " " << weapon.getCapacity() << " " << weapon.getRange() << "\n";
            }
            break;
        }
        case 12: {
            int pilotID, assignedJetID;
            Mystring name, rank;
            bool available;

            cout << "Enter Pilot ID: ";
            cin >> pilotID;
            cin.ignore();
            cout << "Enter Pilot Name: ";
            getline(cin, name);
            cout << "Enter Pilot Rank: ";
            getline(cin, rank);
            cout << "Enter Assigned Jet ID (-1 if none): ";
            cin >> assignedJetID;
            cout << "Is the Pilot Available? (1 for Yes, 0 for No): ";
            cin >> available;

            Pilot newPilot(pilotID, name, rank, assignedJetID, available);
            manager->addPilot(newPilot);
            cout << "Pilot added successfully.\n";
            break;
        }
        case 13: {
            int id;
            Mystring type, model;
            double speed;
            Mystring weaponType;
            int capacity;
            double range;

            cout << "Enter Jet ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Jet Type (BOMBER/STEALTH): ";
            getline(cin, type);
            cout << "Enter Model Name: ";
            getline(cin, model);
            cout << "Enter Speed: ";
            cin >> speed;
            cin.ignore();
            cout << "Enter Weapon Type: ";
            getline(cin, weaponType);
            cout << "Enter Weapon Capacity: ";
            cin >> capacity;
            cout << "Enter Weapon Range: ";
            cin >> range;

            WeaponSystem ws(weaponType, capacity, range);
            FighterJet* newJet = nullptr;

            if (type == "BOMBER") {
                newJet = new BomberJet(id, model, speed, ws);
            }
            else if (type == "STEALTH") {
                newJet = new StealthJet(id, model, speed, ws);
            }
            else {
                cout << "Invalid jet type.\n";
                break;
            }

            manager->addJet(newJet);
            cout << "Jet added successfully.\n";
            break;
        }
        case 14: {
            int pilotID;
            bool available;
            cout << "Enter Pilot ID: ";
            cin >> pilotID;
            cout << "Set availability (1 for Yes, 0 for No): ";
            cin >> available;

            manager->setPilotAvailability(pilotID, available);
            cout << "Pilot availability updated.\n";
            break;
        }
        case 15: {
            int jetID;
            cout << "Enter Jet ID: ";
            cin >> jetID;

            FighterJet* jet = manager->getJetByID(jetID);
            if (jet) {
                cout << "Jet Details:\n";
                cout << "ID: " << jet->getID() << "\n";
                cout << "Model: " << jet->getModel() << "\n";
                cout << "Speed: " << jet->getSpeed() << "\n";
                cout << "Weapon: " << jet->getWeapon().getWeapontype() << "\n";
                cout << "Status: " << jet->getStatus() << "\n";
            }
            else {
                cout << "Jet not found.\n";
            }
            break;
        }
        case 16: {
            int pilotID;
            cout << "Enter Pilot ID: ";
            cin >> pilotID;

            Pilot* pilot = manager->getPilotByID(pilotID);
            if (pilot) {
                cout << "Pilot Details:\n";
                cout << "ID: " << pilot->getPilotID() << "\n";
                cout << "Name: " << pilot->getName() << "\n";
                cout << "Rank: " << pilot->getRank() << "\n";
                cout << "Assigned Jet ID: " << pilot->getAssignedjetID() << "\n";
                cout << "Available: " << (pilot->getAvailability() ? "Yes" : "No") << "\n";
            }
            else {
                cout << "Pilot not found.\n";
            }
            break;
        }
        case 17: {
            int missionID;
            cout << "Enter Mission ID: ";
            cin >> missionID;

            Mission* mission = manager->getMissionByID(missionID);
            if (mission) {
                cout << "Mission Details:\n";
                mission->display();
            }
            else {
                cout << "Mission not found.\n";
            }
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

void displayPilotMenu(int pilotID) {
    FleetManager* manager = FleetManager::getInstance();
    Pilot* pilot = manager->getPilotByID(pilotID);
    int choice;

    if (!pilot) {
        cout << "Error! Pilot not found.\n";
        return;
    }

    do {
        cout << "\nPilot Dashboard - " << pilot->getName() << "\n";
        cout << "1. View Assigned Jet\n";
        cout << "2. View Assigned Missions\n";
        cout << "3. Start Jet Simulation\n";
        cout << "4. View Personal Info\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (pilot->getAssignedjetID() != -1) {
                cout << "Assigned Jet ID: " << pilot->getAssignedjetID() << "\n";
                FighterJet* jet = manager->getJetByID(pilot->getAssignedjetID());
                if (jet) {
                    cout << "\nAssigned Jet:\n";
                    cout << "ID: " << jet->getID() << "\n";
                    cout << "Model: " << jet->getModel() << "\n";
                    cout << "Speed: " << jet->getSpeed() << "\n";
                    cout << "Weapon Type: " << jet->getWeapon().getWeapontype() << "\n";
                    cout << "Status: " << jet->getStatus() << "\n";
                }
                else {
                    cout << "Jet not found.\n";
                }
            }
            else {
                cout << "No jet assigned.\n";
            }
            break;
        }
        case 2: {
            cout << "\nAssigned Missions:\n";
            bool hasMissions = false;
            const auto& allMissions = manager->getMissions();
            for (const auto& mission : allMissions) {
                bool isAssigned = false;
                for (int assignedPilotID : mission.getAssignedpilots()) {
                    if (assignedPilotID == pilotID) {
                        isAssigned = true;
                        break;
                    }
                }

                if (isAssigned) {
                    hasMissions = true;
                    cout << "Mission ID: " << mission.getMissionID() << "\n";
                    cout << "Name: " << mission.getMissionName() << "\n";
                    cout << "Target: " << mission.getLocation() << "\n";
                    cout << "Date: " << mission.getMissionDate() << "\n";

                    cout << "Assigned Jets: ";
                    for (int jetID : mission.getAssignedjets()) {
                        cout << jetID << " ";
                    }
                    cout << "\n\n";
                }
            }
            if (!hasMissions) {
                cout << "No missions assigned.\n";
            }
            break;
        }
        case 3: {
            if (pilot->getAssignedjetID() != -1) {
                FighterJet* jet = manager->getJetByID(pilot->getAssignedjetID());
                if (jet) {
                    runSimulation(jet);
                }
                else {
                    cout << "Jet not found.\n";
                }
            }
            else {
                cout << "No jet.\n";
            }
            break;
        }
        case 4: {
            pilot->displayInfo();
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

int main() {
    FleetManager* manager = FleetManager::getInstance();
    manager->loadAllData();

    Mystring username, password;
    cout << "Fighter Jet Management System\n";
    cout << "Welcome! Login Please :\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (manager->authenticateUser(username, password)) {
        User currentUser = manager->getUserbyusername(username);

        if (currentUser.getRole() == "manager") {
            displayManagerMenu();
        }
        else if (currentUser.getRole() == "pilot") {
            int pilotID = -1;
            for (const auto& pilot : manager->getPilots()) {
                if (pilot.getName() == username) {
                    pilotID = pilot.getPilotID();
                    break;
                }
            }
            if (pilotID != -1) {
                displayPilotMenu(pilotID);
            }
            else {
                cout << "No record found for this user.\n";
            }
        }
    }
    else {
        cout << "Invalid username or password.\n";
    }

    manager->saveAllData();
    return 0;
}

