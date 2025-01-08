#include <SDL2/SDL.h>
#include "constants.h"

class NPC {
public:
    int x, y;  // Position du NPC
    int speed; // Vitesse de déplacement
     static constexpr int width = 50;  // Taille constante
    static constexpr int height = 50;

    NPC(int startX, int startY, int speed)
        : x(startX), y(startY), speed(speed) {}

    void update() {
        y += speed;  // Mouvement uniquement vertical
    if (y > SCREEN_HEIGHT) {
        y = -height;  // Réapparait en haut
    }
    }

    void render(SDL_Renderer* renderer) {
        // Dessiner un carré rouge comme un véhicule placeholder
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rouge
        SDL_Rect destRect = { x, y, 50, 50 };             // Position et taille
        SDL_RenderFillRect(renderer, &destRect);          // Dessiner le rectangle
    }
};
