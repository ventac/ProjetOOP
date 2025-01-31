// main.cpp
// ProjetOOP
// Compilation command: 
// g++ -std=c++17 -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 main.cpp -o main
// https://www.youtube.com/watch?v=JbsmRKi18SI&list=PLJ-vQubfi2yEfPCqb1lr9GX2Kc1NhU4du

#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
#include "constants.h"  // Inclut le fichier des constantes
#include "PlayerCar.h"
#include "Road.h"
#include "NPC.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "Error: " << SDL_GetError();
        return 1;
    }else cout << "OK";
    
    // Creation of RENDERER and WINDOW
    //SDL_Window *window = NULL;
    //SDL_Renderer *renderer = NULL;
    
    // window = SDL_CreateWindow("La Polo de Jarod", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    
    SDL_Window* window = SDL_CreateWindow("Player Car Game", 
                                          SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED, 
                                          SCREEN_WIDTH, 
                                          SCREEN_HEIGHT, 
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    //SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    
     if (!window){
        cerr << "Error: " << SDL_GetError();
        return 1;
    }
    
    
    
    //SDL_SetWindowTitle(window, "La Polo de Jarod");

    // Definition of the road background
    Road road(1, 600);  // Speed = 5, Image size = 600
    // Load image for the road
    if (!road.loadTexture(renderer, "./Resources/road1.bmp")) {
        cerr << "Failed to load road texture!" << endl;

        // Close with error output = 1
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create NPCs
    //std::vector<NPC> npcs;
    //npcs.emplace_back(renderer, "./Resources/road1.bmp", 100, 0, 2); // NPC 1
    //npcs.emplace_back(renderer, "./Resources/road1.bmp", 300, -100, 3); // NPC 2
    //npcs.emplace_back(renderer, "./Resources/road1.bmp", 500, -200, 1); // NPC 3



    // Definition of the Player's car
    PlayerCar playerCar(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100, 50, 100, 2);
    
    // Event detection variable
    SDL_Event event;
    bool quit = false;
    
    // Frames
    Uint32 frameStart = 0;
    int frameTime;

    int posY = 0;
    NPC car1(renderer, "./Resources/IMG/npc_cars/peugeot108.bmp", 100, 0, 1);
    NPC car2(renderer, "./Resources/IMG/npc_cars/peugeot308.bmp", 100, 0, 1);

    
    // Game loop
    while (!quit) {
        while (SDL_PollEvent(&event)){  // Detect quit game
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }

        // Handle player input and avoid colision to borders
        const Uint8* state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_UP]) {
            if (playerCar.getY() > 0)
            playerCar.moveUp();
        }
        if (state[SDL_SCANCODE_DOWN]) {
            if (playerCar.getY() < SCREEN_HEIGHT)
            playerCar.moveDown();
        }
        if (state[SDL_SCANCODE_LEFT]) {
            if (playerCar.getX() > 0)
            playerCar.moveLeft();
        }
        if (state[SDL_SCANCODE_RIGHT]) {
            if (playerCar.getX() < SCREEN_WIDTH)
            playerCar.moveRight();
        }



        // Rendering 
        // Clear the screen with a black background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);        

        // Render the road
        road.render(renderer);

        // Render the NPC cars
          // Update and render NPCs
        car1.update();
        car1.render(renderer);
        car2.update();
        car2.render(renderer);

        // for (auto& npc : npcs) {
        //     npc.update();
        //     npc.render(renderer);
        // }


        // Render the player car
        playerCar.render(renderer);
        SDL_RenderPresent(renderer);
        
        // Control of the framerate
        // frameTime = SDL_GetTicks() - frameStart;
        // if (frameTime < FRAME_DELAY) {
        //     SDL_Delay(FRAME_DELAY - frameTime);
        // }
        
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
    
}

// Test GitHub XCode