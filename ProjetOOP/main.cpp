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
#include <random>
#include <vector>
#include <cstdlib>  // Pour rand() et srand()
#include <ctime>    // Pour seed aléatoire
#include "NPC.h"
#include "constants.h" // Inclut le fichier des constantes

using namespace std;

void renderRoad(SDL_Renderer **r, int &posY)
{
    // Update position for scrolling down
    posY += SPEED;
    if (posY >= IMAGE_SIZE)
    {
        posY = 0;
    }

    SDL_Surface *image = SDL_LoadBMP(ROAD_IMAGE_PATH); // Load the image

    if (!image)
    {
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Texture *pTextureImage = SDL_CreateTextureFromSurface(*r, image); // Convert to texture
    SDL_FreeSurface(image);                                               // Free the surface

    if (!pTextureImage)
    {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Clear the screen with a black background
    SDL_SetRenderDrawColor(*r, 0, 0, 0, 255);
    SDL_RenderClear(*r);

    // Render multiple segments of the road image to cover the entire screen
    for (int i = -1; i <= SCREEN_HEIGHT / IMAGE_SIZE + 1; ++i)
    {
        SDL_Rect dest = {0, posY - i * IMAGE_SIZE, SCREEN_WIDTH, IMAGE_SIZE};
        SDL_RenderCopy(*r, pTextureImage, NULL, &dest);
    }

    // Update the screen
    // Destroy the texture after rendering
    SDL_DestroyTexture(pTextureImage);
}


int main(int argc, const char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);

    if (!window)
    {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_SetWindowTitle(window, "La Polo de Jarod");

    // Initialiser le générateur de nombres aléatoires
    //srand(static_cast<unsigned int>(time(nullptr)));

    // Nombre de carrés à générer
    const int numNPCs = 5;  // Ajustez ce nombre selon vos besoins
    std::vector<NPC> npcs;
    const int min = 50;
    const int max = SCREEN_WIDTH - 50;

    mt19937 gen(time(0));  // Seed avec le temps actuel
    // Créer les NPCs avec des positions aléatoires
   for (int i = 0; i < numNPCs; ++i) {
    //srand(time(0));
    uniform_int_distribution<int> dist(min, max);
    int randomValue = dist(gen);
    int startX =  randomValue; // Position X complètement aléatoire
    int startY = 0;//rand() % SCREEN_HEIGHT; // Position Y complètement aléatoire
    // int startX = rand() % (SCREEN_WIDTH - 50);  // Position X complètement aléatoire
    // int startY = 0;//rand() % SCREEN_HEIGHT; // Position Y complètement aléatoire
    int speed = 1;          // Vitesse aléatoire entre 1 et 5
    npcs.emplace_back(startX, startY, speed);
}

    SDL_Event event;
    bool quit = false;
    Uint32 frameStart = 0;
    int frameTime;
    int posY = 0;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        renderRoad(&renderer, posY);

        // Update and render each NPC
        for (auto &npc : npcs)
        {
            npc.update();
            npc.render(renderer);
        }

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
