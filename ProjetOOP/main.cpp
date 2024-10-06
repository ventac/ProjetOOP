//
//  main.cpp
//  ProjetOOP
//
//  Created by Guilherme Ventapane on 6/10/24.
// https://www.youtube.com/watch?v=JbsmRKi18SI&list=PLJ-vQubfi2yEfPCqb1lr9GX2Kc1NhU4du

#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int FPS = 60; // Desired frame rate
const int FRAME_DELAY = 1000 / FPS; // Frame delay in milliseconds
const int VITESSE = 1;


using namespace std;


// Function to display an image using SDL_Renderer
void afficherRoute(SDL_Renderer** r, int& posY){//, int posX, int posY) {
    
    const int TAILLE_IMAGE = 600;
    
    // Update the offset position
    posY -= VITESSE;
    if (posY <= -TAILLE_IMAGE) {
        posY = 0;
    }
    
    SDL_Surface* image = SDL_LoadBMP("/Users/guilhermeventapane/Documents/Dev/ProjetOOP/ProjetOOP/Resources/IMG/road1.bmp");
    if (!image) {
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Texture* pTextureImage = SDL_CreateTextureFromSurface(*r, image); // surface into texture
    if (!pTextureImage) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(image);
        return;
    }

    SDL_FreeSurface(image); // free the surface

    // Clear the renderer and draw the image
    SDL_SetRenderDrawColor(*r, 0, 0, 0, 255); // black background
    SDL_RenderClear(*r);

    // Dimensoes da tela
    
    //int pos
    
    SDL_Rect dest = { 0, posY, SCREEN_WIDTH, TAILLE_IMAGE};
    SDL_Rect dest2 = { 0, posY + TAILLE_IMAGE, SCREEN_WIDTH, TAILLE_IMAGE};
    SDL_Rect dest3 = { 0, posY + (TAILLE_IMAGE * 2), SCREEN_WIDTH, TAILLE_IMAGE};
    SDL_RenderCopy(*r, pTextureImage, NULL, &dest); // copy texture to the renderer
    SDL_RenderCopy(*r, pTextureImage, NULL, &dest2);
    SDL_RenderCopy(*r, pTextureImage, NULL, &dest3);
    
    // Faire la texture révenir au debut
    //if (posY)
    
    
    SDL_RenderPresent(*r); // update the screen

    // Destroy the texture after rendering
    SDL_DestroyTexture(pTextureImage);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "error" << SDL_GetError();
        return 1;
    }else cout << "OK";
    
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    
    //window = SDL_CreateWindow("La Polo de Jarod", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    
    SDL_CreateWindowAndRenderer( SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    
    if (!window){
        cerr << "error" << SDL_GetError();
        return 1;
    }
    
    SDL_SetWindowTitle(window, "La Polo de Jarod");
    
    
    SDL_Event event;
    bool quit = false;
    
    // Frames
    Uint32 frameStart = NULL;
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
        //SDL_SetRenderDrawColor(renderer, 200, 20, 0, 255); // R=200, G=20, B=0
        //DL_RenderClear(renderer);
        afficherRoute(&renderer, posY);
        //SDL_RenderPresent(renderer);
        
        
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
