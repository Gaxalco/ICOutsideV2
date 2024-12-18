#include "headers/main.h"



void GetTextureSize(SDL_Texture *texture, int *w, int *h) {
    if ((w == NULL) || (h == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (SDL_QueryTexture(texture, NULL, NULL, w, h) < 0) {
        fprintf(stderr, "Error GetTextureSize : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}