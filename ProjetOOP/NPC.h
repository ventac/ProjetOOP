#ifndef NPC_H
#define NPC_H

#include <string>
#include <SDL2/SDL.h>

class NPC {
public:
    int x, y; // NPC position
    int speed; // Movement speed
    SDL_Texture* texture; // NPC texture

    NPC(SDL_Renderer* renderer, const std::string& imagePath, int startX, int startY, int speed);
    ~NPC();

    void update();
    void render(SDL_Renderer* renderer);
};

#endif // NPC_H