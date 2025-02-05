#ifndef CONSTANTS_H
#define CONSTANTS_H

// Dimensions de l'écran
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

// Frame rate
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

// Vitesse de défilement
const int SPEED = 1;

// Fichiers de ressources
const char IMG_ROAD[] = "./Resources/road1.bmp";
const char IMG_CAR1[] = "./Resources/IMG/npc_cars/peugeot108.bmp";
const char IMG_CAR2[] = "./Resources/IMG/npc_cars/peugeot308.bmp";     
const char IMG_PLAYER[] = "./Resources/poloRougeOK.bmp";     
const char IMG_GAMEOVER[] = "./Resources/gameOver.bmp";     



// NPC
const int NPC_MIN_SPEED = 0;  // Slowing down
const int NPC_MAX_SPEED = 2;  // Speeding up



#endif // CONSTANTS_H
