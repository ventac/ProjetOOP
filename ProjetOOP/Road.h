#ifndef ROAD_H
#define ROAD_H

#include <SDL2/SDL.h>
#include <iostream>

class Road {
private:
    int speed;         
    // Scrolling speed
    int imageSize;     
    // Size of the road image
    SDL_Texture* texture; // Texture of the road image

public:
    int posY;          
    // Current position of the road for scrolling

    // Constructor
    Road(int imageSize);

    // Destructor
    ~Road();

    // Load road image
    bool loadTexture(SDL_Renderer* renderer, const char* filePath);

    // Render the road
    void render(SDL_Renderer* renderer);
};

#endif // ROAD_H