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

// Fonction pour détecter les collisions entre la voiture du joueur et les NPCs
bool checkCollision(const PlayerCar& player, const NPC& npc) {
    SDL_Rect playerRect = {player.getX(), player.getY(), 50, 100};
    SDL_Rect npcRect = {npc.x, npc.y, 50, 100};
    return SDL_HasIntersection(&playerRect, &npcRect);
}

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

    bool running = true;
    while (running) {
        // Définition de la voiture du joueur
         // Create NPCs
    //std::vector<NPC> npcs;
    //npcs.emplace_back(renderer, "./Resources/road1.bmp", 100, 0, 2); // NPC 1
    //npcs.emplace_back(renderer, "./Resources/road1.bmp", 300, -100, 3); // NPC 2
    //npcs.emplace_back(renderer, "./Resources/road1.bmp", 500, -200, 1); // NPC 3



    // Definition of the Player's car
        PlayerCar playerCar(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100, 50, 100, 2);
        
        // Création d'un NPC
    // Frames
    Uint32 frameStart = 0;
    int frameTime;

    int posY = 0;
    NPC car1(renderer, "./Resources/IMG/npc_cars/peugeot108.bmp", 100, 0, 1);
    NPC car2(renderer, "./Resources/IMG/npc_cars/peugeot308.bmp", 100, 0, 1);        
        // Variable de détection d'événements
        SDL_Event event;
        bool quit = false;
        bool gameOver = false;
        
        // Boucle du jeu
        while (!quit) {
            while (SDL_PollEvent(&event)){  // Détection de la fermeture du jeu
                if (event.type == SDL_QUIT){
                    quit = true;
                    running = false;
                }
                if (gameOver && event.type == SDL_KEYDOWN) {
                    if (event.key.keysym.sym == SDLK_q) {
                        quit = true;
                        running = false;
                    } else if (event.key.keysym.sym == SDLK_r) {
                        quit = true;
                    }
                }
            }

            if (!gameOver) {
                // Gestion des entrées du joueur et prévention des collisions avec les bords
                const Uint8* state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_UP] && playerCar.getY() > 0) {
                    playerCar.moveUp();
                }
                if (state[SDL_SCANCODE_DOWN] && playerCar.getY() < SCREEN_HEIGHT) {
                    playerCar.moveDown();
                }
                if (state[SDL_SCANCODE_LEFT] && playerCar.getX() > 0) {
                    playerCar.moveLeft();
                }
                if (state[SDL_SCANCODE_RIGHT] && playerCar.getX() < SCREEN_WIDTH) {
                    playerCar.moveRight();
                }

                // Mise à jour du NPC
                car2.update();

                // Vérification des collisions
                if (checkCollision(playerCar, car2)) {
                    gameOver = true;
                }
            }

            // Rendu
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fond noir
            SDL_RenderClear(renderer);
            
            // Rendu de la route
            road.render(renderer);
            
            // Rendu des NPCs
            car2.render(renderer);
            
            // Rendu de la voiture du joueur
            playerCar.render(renderer);

            // Affichage Game Over si collision
            if (gameOver) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_Rect gameOverRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4};
                SDL_RenderFillRect(renderer, &gameOverRect);
                
                // Texte "Game Over"
                cout << "Game Over! Press R to Restart or Q to Quit." << endl;
            }

            SDL_RenderPresent(renderer);
        }
    }
    
    // Nettoyage et fermeture
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
