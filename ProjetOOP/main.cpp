// main.cpp
// ProjetOOP
// Compilation command: 
//g++ -std=c++17 -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 main.cpp PlayerCar.cpp Road.cpp NPC.cpp ImageManager.cpp -o main
// https://www.youtube.com/watch?v=JbsmRKi18SI&list=PLJ-vQubfi2yEfPCqb1lr9GX2Kc1NhU4du

#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
#include "constants.h"  // Inclut le fichier des constantes
#include "PlayerCar.h"
#include "Road.h"
#include "NPC.h"
#include "ImageManager.h"

using namespace std;

// Fonction pour détecter les collisions entre la voiture du joueur et les NPCs
bool checkCollision(const PlayerCar& player, const NPC& npc) {
    SDL_Rect playerRect = {player.getX(), player.getY(), 50, 100};
    SDL_Rect npcRect = {npc.x, npc.y, 50, 100};
    return SDL_HasIntersection(&playerRect, &npcRect);
}

// Function overload 
bool checkCollision(const NPC& npc1, const NPC& npc2) {
    SDL_Rect playerRect = {npc1.x, npc1.y, 50, 100};
    SDL_Rect npcRect = {npc2.x, npc2.y, 50, 100};
    return SDL_HasIntersection(&playerRect, &npcRect);
}

int main(int argc, const char * argv[]) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "Error: " << SDL_GetError();
        return 1;
    }else cout << "OK";
    
    SDL_Window* window = SDL_CreateWindow("La Polo de Jarod", 
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
    Road road(600);  // Image size = 600
    // Load image for the road
    if (!road.loadTexture(renderer, IMG_ROAD)) {
        cerr << "Failed to load road texture!" << endl;

        // Close with error output = 1
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* img_gameover = ImageManager::LoadTexture(IMG_GAMEOVER, renderer);

    bool running = true;
    while (running) {

        // Definition of the Player's car
        PlayerCar playerCar(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100, 50, 100, 2, IMG_PLAYER);

        // Création d'un NPC
        // Frames
        Uint32 frameStart = 0;
        int frameTime;

        int posY = 0;
        NPC car1(renderer, IMG_CAR1, 100, 0, 1);
        NPC car2(renderer, IMG_CAR2, 100, 0, 1);        

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

                // Updating NPC position
                car1.update();
                car2.update();

                // Collision detection
                if (checkCollision(playerCar, car1)) 
                gameOver = true;
                
                if (checkCollision(playerCar, car2)) 
                gameOver = true;

                if (checkCollision(car1, car2)) {
                    car2.x += rand()%(100-50 + 1) + 50;
                    // Between 50 and 100 pixels of deplacement
                }
            }

            // Rendu
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fond noir
            SDL_RenderClear(renderer);
            
            // Rendu de la route
            if (!gameOver){
                road.render(renderer);
                road.posY += 1;
            }

            // Rendu des NPCs
            car1.render(renderer);
            car2.render(renderer);
            
            // Rendu de la voiture du joueur
            playerCar.render(renderer);

            // Affichage Game Over si collision
            if (gameOver) {

                int imgWidth, imgHeight;
                ImageManager::GetImageDimensions(img_gameover, imgWidth, imgHeight);
                int x = (SCREEN_WIDTH - imgWidth) / 2;
                int y = (SCREEN_HEIGHT - imgHeight) / 2;

                // Render the "Game Over" image
                if (img_gameover) {  // Checking to make sure image was loaded
                    ImageManager::Render(img_gameover, renderer, x, y, imgWidth, imgHeight);
                } else {
                    std::cerr << "Error: Game Over image not loaded!" << std::endl;
                }

                SDL_RenderPresent(renderer);

                // Wait for user input to either restart or quit
                bool waitingForInput = true;
                while (waitingForInput) {
                    SDL_Event event;
                    while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
                            quit = true;
                            waitingForInput = false;
                        } 
                        // Listen for key press events
                        if (event.type == SDL_KEYDOWN) {
                            if (event.key.keysym.sym == SDLK_q) {
                                // Quit the game
                                quit = true;
                                waitingForInput = false;
                                running = false;
                            } else if (event.key.keysym.sym == SDLK_r) {
                                // Restart the game
                                //gameOver = false;  // Reset the game over flag
                                quit = true;
                                // Reset other game state elements here (player position, NPCs, etc.)
                                waitingForInput = false;
                            }
                        }
                    }
                }
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
