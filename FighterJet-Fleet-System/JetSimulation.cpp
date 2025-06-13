#include "JetSimulation.h"
#include "raylib.h"

JetSimulation::JetSimulation() {
    posX = 400;
    posY = 500;
    speed = 3.0f;
    jetTexture = LoadTexture("resources/jet.png");
}

JetSimulation::~JetSimulation() {
    UnloadTexture(jetTexture);
}

void JetSimulation::moveForward() {
    posY -= speed;
}

void JetSimulation::moveBackward() {
    posY += speed;
}

void JetSimulation::moveLeft() {
    posX -= speed;
}

void JetSimulation::moveRight() {
    posX += speed;
}

void JetSimulation::draw() {
    DrawTexturePro(jetTexture,{ 0, 0, (float)jetTexture.width, (float)jetTexture.height },{ posX, posY, 64, 64 },{ 32, 32 }, 0.0f, WHITE);
}