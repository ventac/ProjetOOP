#ifndef PLAYERCAR_H
#define PLAYERCAR_H

#include <SDL2/SDL.h>

class PlayerCar {
private:
    int x;        // X-coordinate of the car
    int y;        // Y-coordinate of the car
    int width;    // Width of the car
    int height;   // Height of the car
    int speed;    // Movement speed of the car

public:
    // Constructor
    PlayerCar(int startX, int startY, int carWidth, int carHeight, int carSpeed);

    // Movement methods
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    // Rendering method
    void render(SDL_Renderer* renderer);

    // Accessors
    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);
};

#endif  // PLAYERCAR_H