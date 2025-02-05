#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class ImageManager {
public:
    static SDL_Texture* LoadTexture(const std::string& filePath, SDL_Renderer* renderer);
    static void Render(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h);
    static void Cleanup(SDL_Texture* texture);
    
    // Add method to get image dimensions (this assumes you have a way to load textures)
    static void GetImageDimensions(SDL_Texture* texture, int &width, int &height) {
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

};

#endif // IMAGE_MANAGER_H