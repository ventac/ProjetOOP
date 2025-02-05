#include "Road.h"
#include "constants.h"

// Constructor
Road::Road(int imageSize)
    : posY(0), imageSize(imageSize), texture(nullptr) {}

// Destructor
Road::~Road() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

// Load road image
bool Road::loadTexture(SDL_Renderer* renderer, const char* filePath) {
    SDL_Surface* image = SDL_LoadBMP(filePath);
    if (!image) {
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

// Render the road
void Road::render(SDL_Renderer* renderer) {
    
    //posY += speed;
    
    if (posY >= imageSize) {
        posY = 0;
    }

    // Render multiple segments of the road image to cover the entire screen
    for (int i = -1; i <= SCREEN_HEIGHT / imageSize + 1; ++i) {
        SDL_Rect dest = {0, posY - i * imageSize, SCREEN_WIDTH, imageSize};
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }

}