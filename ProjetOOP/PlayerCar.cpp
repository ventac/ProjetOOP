#include "PlayerCar.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "constants.h"

// Constructor
PlayerCar::PlayerCar(SDL_Renderer* renderer, int startX, int startY, int carWidth, int carHeight, int carSpeed, const std::string& imagePath)
    : x(startX), y(startY), width(carWidth), height(carHeight), speed(carSpeed), texture(nullptr) {
        SDL_Surface* tempSurface = SDL_LoadBMP(imagePath.c_str());
    if (!tempSurface) {
        std::cerr << "Error loading NPC image: " << SDL_GetError() << std::endl;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    }
    }

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
    SDL_Rect destRect = {x, y, width, height};
    if(texture) {
        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    } else {
        // Fallback si la texture n'est pas chargée
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &destRect);
    }
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