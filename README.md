# 🛩️ Fighter Fleet Management System

An Object-Oriented Programming (OOP) project in C++ to simulate the management of a military fighter fleet. The system handles jets, pilots, and mission logistics with support for 2D movement simulation and role-based access control. It is designed to be compatible with **SFML** for future graphical enhancements.

---

## 📦 Project Features

### 🧠 Object-Oriented Principles
- **Abstraction:** Via abstract classes for core jet behavior.
- **Inheritance:** `FighterJet` as a base class, extended by `StealthJet` and `BomberJet`.
- **Polymorphism:** Jet launching operations implemented polymorphically.
- **Encapsulation:** Structured management of pilot, mission, and user data.

### ⚙️ Core Functionalities
- Add, launch, and assign fighter jets.
- Assign pilots and track their availability.
- Plan and manage complex missions involving multiple assets.
- Log and monitor jet maintenance status.
- Simulate 2D jet movement (forward, backward, left, right).
- Secure user login system with role-based access (Admin / Limited).

---

## 📊 UML Diagram

The diagram below illustrates class relationships between key components such as `FighterJet`, `StealthJet`, `BomberJet`, `Mission`, `Pilot`, `User`, and `FleetManager`.

![UML Diagram](./uml.png)

> **Source**: Designed using [draw.io](https://draw.io)

---

## 🔁 System Activity Flow

1. **User Authentication**
   - Login with username, password, and defined role.

2. **Role-Based Dashboard**
   - **Admin Access:**
     - Add/view jets, pilots, and missions.
     - Assign pilots and jets.
     - Launch and control jet movement.
     - Log maintenance activities.
   - **Limited Access:**
     - View jets and missions.
     - Launch jets (if authorized).

3. **Jet Movement Simulation**
   - Jet moves on a virtual 2D grid using directional methods:
     - `moveForward()`
     - `moveBackward()`
     - `moveLeft()`
     - `moveRight()`

4. **Mission Control**
   - Plan operations by assigning jets and pilots.
   - Define mission targets, schedule, and objectives.

5. **Visual Simulation (Planned)**
   - Future integration with SFML to render flight movements and UI.

---

## 🔄 Flowchart Overview

This flowchart outlines the application's logic, starting from user authentication through system operations like jet control and mission handling.

![Flow Chart](./flowchart.png)

> **Source**: Designed using [draw.io](https://draw.io)

---

## 🔐 User Roles & Permissions

| Role   | Access Level                                      |
|--------|---------------------------------------------------|
| Admin  | Full access: add, assign, launch, log, plan       |
| User   | Limited access: view and launch (restricted)      |

---

## 🚀 Planned Enhancements
- 📊 **SFML-based graphical simulation**
- 💾 **Persistent data storage** (load/save)
- 🖥️ **Graphical User Interface (GUI)** for login and management

---

## 🧰 Tools Used

- **Language:** C++
- **Graphics:** SFML (future integration)
- **Diagram Design:** [draw.io](https://draw.io)

---

## 🔗 Source Diagram Files

Edit or view the original editable diagrams here:
- [UML Diagram (Draw.io Viewer)](https://app.diagrams.net/)
- [Flow Chart (Draw.io Viewer)](https://app.diagrams.net/)

---
