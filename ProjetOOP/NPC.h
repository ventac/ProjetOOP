#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
#include "constants.h"

class NPC {
public:
    int x, y; // Position du NPC
    int speed; // Vitesse de déplacement
    SDL_Texture* texture; // Texture du NPC

    NPC(SDL_Renderer* renderer, const std::string& imagePath, int startX, int startY, int speed)
        : x(startX), y(startY), speed(speed) {
        SDL_Surface* tempSurface = SDL_LoadBMP(imagePath.c_str());
        if (!tempSurface) {
            std::cerr << "Error loading NPC image: " << SDL_GetError() << std::endl;
            texture = nullptr;
        } else {
            texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
            SDL_FreeSurface(tempSurface);
        }
    }

    ~NPC() {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }

    void update() {
        // Simple vertical movement for demo purposes
        y += speed;
        if (y > SCREEN_HEIGHT) {
            y = -50; // Reposition above the screen when offscreen
        }
    }

    void render(SDL_Renderer* renderer) {
        SDL_Rect destRect = { x, y, 50, 50 }; // Adjust size as needed
        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    }
};
