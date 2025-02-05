#include "ImageManager.h"

SDL_Texture* ImageManager::LoadTexture(const std::string& filePath, SDL_Renderer* renderer) {
    SDL_Surface* loadedSurface = SDL_LoadBMP(filePath.c_str());  // Load BMP image
    if (!loadedSurface) {
        std::cerr << "Error loading BMP image " << filePath << ": " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);  // Free surface after creating texture

    if (!texture) {
        std::cerr << "Error creating texture from " << filePath << ": " << SDL_GetError() << std::endl;
    }

    return texture;
}

void ImageManager::Render(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h) {
    SDL_Rect dstRect = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
}

void ImageManager::Cleanup(SDL_Texture* texture) {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}