#include "headers/main.h"



void DrawPoint(App *app, SDL_Point *point) {
    if (point == NULL) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    SDL_RenderDrawPoint(app->renderer, point->x, point->y);
}


void DrawLine(App *app, SDL_Point *point1, SDL_Point *point2) {
    if ((point1 == NULL) || (point2 == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    SDL_RenderDrawLine(app->renderer, point1->x, point1->y, point2->x, point2->y);
}


void DrawRect(App *app, SDL_Rect *rect, bool fill) {
    if (rect == NULL) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (fill) {
        SDL_RenderFillRect(app->renderer, rect);
    } else {
        SDL_RenderDrawRect(app->renderer, rect);
    }
}

void SetWindowColor(App *app) {
    if (SDL_SetRenderDrawColor(app->renderer, app->windowColor.r, app->windowColor.g, app->windowColor.b, app->windowColor.a) < 0) {
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

void SetTextureColor(SDL_Texture *texture, SDL_Color color) {
    if (SDL_SetTextureColorMod(texture, color.r, color.g, color.b) < 0) {
        fprintf(stderr, "Error setTextureColor : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}