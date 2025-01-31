#include "NPC.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "constants.h"

// Constructor
NPC::NPC(SDL_Renderer* renderer, const std::string& imagePath, int startX, int startY, int speed)
    : x(startX), y(startY), speed(speed), texture(nullptr) {
    SDL_Surface* tempSurface = SDL_LoadBMP(imagePath.c_str());
    if (!tempSurface) {
        std::cerr << "Error loading NPC image: " << SDL_GetError() << std::endl;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    }
}

// Destructor
NPC::~NPC() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

// Update NPC position
void NPC::update(/*Direction*/) {
    // Making the speed variable
    int randSpeed = rand()%(NPC_MAX_SPEED-NPC_MIN_SPEED + 1) + NPC_MIN_SPEED;
    y += speed + randSpeed;  // Move forward
    //x += // Move slightly to the sides
    
    // This will reset the NPC's car when it reaches bottom (or top)
    if (y > SCREEN_HEIGHT) {        
        y = -50; // Reposition above the screen when offscreen
        // Random new position for x
        x = rand()%(SCREEN_WIDTH + 1);
    }
}

// Render NPC on the screen
void NPC::render(SDL_Renderer* renderer) {
    SDL_Rect destRect = { x, y, 50, 100 }; // Adjust size as needed
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}