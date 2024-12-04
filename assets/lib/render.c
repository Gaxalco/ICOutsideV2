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