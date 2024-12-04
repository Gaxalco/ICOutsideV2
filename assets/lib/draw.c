#include "main.h"



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