#include "main.h"



SDL_Texture *LoadTexture(App *app, const char *path) {
    SDL_Surface *surface = LoadSurface(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, surface);
    if (texture == NULL) {
        fprintf(stderr, "Error loadTexture : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Surface *LoadSurface(const char *path) {
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (surface == NULL) {
        fprintf(stderr, "Error loadSurface : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return surface;
}

void SetWindowColor(App *app, SDL_Color color) {
    if (SDL_SetRenderDrawColor(app->renderer, color.r, color.g, color.b, color.a) < 0) {
        fprintf(stderr, "Error setWindowColor : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if (SDL_RenderClear(app->renderer) < 0) {
        fprintf(stderr, "Error setWindowColor : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void RandomColor(SDL_Color *color) {
    if (color == NULL) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    color->r = rand() % 256;
    color->g = rand() % 256;
    color->b = rand() % 256;
    color->a = 255;
}