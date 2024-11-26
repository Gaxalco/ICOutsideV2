#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



// Structs

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;

    int window_size_x;
    int window_size_y;
} App;

typedef struct {
    SDL_Surface *image;

    SDL_Rect *hitbox;
    SDL_Point *pos;

    int speed;
} Entity;