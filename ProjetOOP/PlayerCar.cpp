#include "PlayerCar.h"

// Constructor
PlayerCar::PlayerCar(int startX, int startY, int carWidth, int carHeight, int carSpeed)
    : x(startX), y(startY), width(carWidth), height(carHeight), speed(carSpeed) {}

// Movement methods
void PlayerCar::moveUp() {
    y -= speed;
}

void PlayerCar::moveDown() {
    y += speed;
}

void PlayerCar::moveLeft() {
    x -= speed;
}

void PlayerCar::moveRight() {
    x += speed;
}

// Rendering method
void PlayerCar::render(SDL_Renderer* renderer) {
    SDL_Rect carRect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color for the car
    SDL_RenderFillRect(renderer, &carRect);
}

// Accessors
// Use for collision detection
int PlayerCar::getX() const {
    return x;
}

int PlayerCar::getY() const {
    return y;
}

void PlayerCar::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}