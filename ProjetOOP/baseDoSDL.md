//
//  main.cpp
//  ProjetOOP
//
//  Created by Guilherme Ventapane on 6/10/24.
// https://www.youtube.com/watch?v=JbsmRKi18SI&list=PLJ-vQubfi2yEfPCqb1lr9GX2Kc1NhU4du

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "error" << SDL_GetError();
        return 1;
    }else cout << "OK";
    
    
    SDL_Window *window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    
    if (!window){
        cout << "error" << SDL_GetError();
        return 1;
    }
    
    SDL_Event event;
    bool quit;
    
    while (!quit) {
        // Event handling
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }
        // rendering
        
        // update
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
    
}
