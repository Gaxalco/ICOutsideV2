#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Enums

typedef enum {
    MAP,
    PLAYER,
    WEAPONS,
    MAP_TOP,
    AllRenderLayers
} RenderLayers;


typedef enum {
    Icon,
    Kungfu,
    AllPaths
} Paths;

char *paths[AllPaths] = {
    "assets/images/window/icon.bmp",
    "assets/images/characters/Hipster/kungfou.bmp"
};


// Structs

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *icon;

    int window_size_x;
    int window_size_y;
} App;

typedef struct {
    SDL_Rect hitbox;

    SDL_Point position;
    SDL_Texture *texture;

    int speed;
    int health;
    int armor;
    int ammo;
} Player;