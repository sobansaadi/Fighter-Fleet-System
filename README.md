# Soban-oop-project

# 🛩️ Fighter Fleet Management System

A C++ Object-Oriented Programming (OOP) project designed to manage a fleet of fighter jets, pilots, and missions. It features  movement simulation, user access control, and future compatibility with SFML for graphics.

---

## 📌 Features

### ✅ Object-Oriented Design
- Abstraction via abstract classes
- Inheritance: `FighterJet` → `StealthJet`, `BomberJet`
- Polymorphism for launching jets
- Encapsulation of pilot, mission, and user data

### ✅ Core Functionalities
- Manage jets (add, launch, assign)
- Track pilot assignments and availability
- Plan missions with multiple jets and pilots
- Log and track maintenance for each jet
- Move jets in 2D space (forward, backward, left, right)
- User login system with access roles (Admin / Else)

---
## 📊 UML Diagram

The UML diagram below illustrates the relationship between key classes like `FighterJet`, `StealthJet`, `BomberJet`, `Mission`, `Pilot`, `User`, and `FleetManager`.

![UML Diagram]("images/uml.png")

## 🔄 Activity Flow

1. **User Login** (with username, password, role)
2. **Main Menu Based on Role**
   - Add / view jets, pilots, missions
   - Assign pilots and jets
   - Launch and move jets
   - Log maintenance
3. **Jet Movement Simulation**
   - Move jets on 2D grid using methods:
     - `moveForward()`
     - `moveBackward()`
     - `moveLeft()`
     - `moveRight()`
4. **Mission Planning**
   - Assign multiple jets and pilots to each mission
   - Track mission targets and schedule
5. ** SFML Graphics**
   - Will use SFML to visually simulate aircraft movement

---

## 🔁 Flow Chart

This flow chart shows how the program logic flows from user login to system functionalities like managing jets, pilots, and missions.

![Flow Chart](images/flowchart.png)

---
## 🔐 User Roles

| Role     | Permissions                      |
|----------|----------------------------------|
| Admin    | Full access to all features      |
| Else     | Limited to viewing and launching |

---

## 🛠️ Future Enhancements
- Will Add SFML-based visual simulation
- Save/load data from files
- Will Add GUI login interface
