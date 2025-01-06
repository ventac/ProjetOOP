//  main.cpp
//  ProjetOOP
// Compilation command: 
// g++ -std=c++17 -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 main.cpp -o main
//
//
//
// https://www.youtube.com/watch?v=JbsmRKi18SI&list=PLJ-vQubfi2yEfPCqb1lr9GX2Kc1NhU4du

#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int FPS = 60; // Desired frame rate
const int FRAME_DELAY = 1000 / FPS; // Frame delay in milliseconds
const int SPEED = 1;

using namespace std;

void renderRoad(SDL_Renderer** r, int& posY) {
    const int IMAGE_SIZE = 600; // Size of the road image
    const int SCREEN_HEIGHT = 800; // Replace with the actual screen height
    const int SCREEN_WIDTH = 800;  // Replace with the actual screen width

    // Update position for scrolling down
    posY += SPEED;
    if (posY >= IMAGE_SIZE) {
        posY = 0;
    }

    SDL_Surface* image = SDL_LoadBMP("./Resources/road1.bmp"); // Load the image

    if (!image) {
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Texture* pTextureImage = SDL_CreateTextureFromSurface(*r, image); // Convert to texture
    SDL_FreeSurface(image); // Free the surface

    if (!pTextureImage) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Clear the screen with a black background
    SDL_SetRenderDrawColor(*r, 0, 0, 0, 255);
    SDL_RenderClear(*r);

    // Render multiple segments of the road image to cover the entire screen
    for (int i = -1; i <= SCREEN_HEIGHT / IMAGE_SIZE + 1; ++i) {
        SDL_Rect dest = { 0, posY - i * IMAGE_SIZE, SCREEN_WIDTH, IMAGE_SIZE };
        SDL_RenderCopy(*r, pTextureImage, NULL, &dest);
    }

    // Update the screen
    SDL_RenderPresent(*r);

    // Destroy the texture after rendering
    SDL_DestroyTexture(pTextureImage);
}


int main(int argc, const char * argv[]) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "Error: " << SDL_GetError();
        return 1;
    }else cout << "OK";
    
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    
    // window = SDL_CreateWindow("La Polo de Jarod", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    
    if (!window){
        cerr << "Error: " << SDL_GetError();
        return 1;
    }
    
    SDL_SetWindowTitle(window, "La Polo de Jarod");
    
    SDL_Event event;
    bool quit = false;
    
    // Frames
    Uint32 frameStart = 0;
    int frameTime;

    int posY = 0;
    
    while (!quit) {
        // Event handling --------------------------------------------------
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }
        // Rendering -------------------------------------------------------
        // SDL_SetRenderDrawColor(renderer, 200, 20, 0, 255); // R=200, G=20, B=0
        // SDL_RenderClear(renderer);
        renderRoad(&renderer, posY);
        // SDL_RenderPresent(renderer);
        
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DELAY) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
        
        // Update ----------------------------------------------------------
        
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
    
}

// Test GitHub XCode