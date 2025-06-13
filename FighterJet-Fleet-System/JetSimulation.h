#ifndef JETSIMULATION_H
#define JETSIMULATION_H

#include "raylib.h"

class JetSimulation {
private:
    float posX, posY;
    float speed;
    Texture2D jetTexture;

public:
    JetSimulation();
    ~JetSimulation();
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void draw();
};

#endif
