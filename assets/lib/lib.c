#include "main.h"


// Useful small functions

void delay(unsigned int ms) {
    SDL_Delay(ms);
}

bool pointInRect(SDL_Point *P, SDL_Rect *R) {
    if ((P ==  NULL) || (R == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_PointInRect(P, R);
}

bool intersect(SDL_Rect *A, SDL_Rect *B) {
    if ((A ==  NULL) || (B == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_HasIntersection(A, B);
}

bool intersectResult(SDL_Rect *A, SDL_Rect *B, SDL_Rect *Intersection) {
    if ((A ==  NULL) || (B == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_IntersectRect(A, B, Intersection);
}

void updateApp(App *app) {
    SDL_RenderPresent(app->renderer);
}

void drawPoint(App *app, SDL_Point *point) {
    if (point == NULL) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    SDL_RenderDrawPoint(app->renderer, point->x, point->y);
}

void drawLine(App *app, SDL_Point *point1, SDL_Point *point2) {
    if ((point1 == NULL) || (point2 == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    SDL_RenderDrawLine(app->renderer, point1->x, point1->y, point2->x, point2->y);
}

void drawRect(App *app, SDL_Rect *rect, bool fill) {
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

// Getters

void updateWindowSize(App *app) {
    SDL_GetWindowSize(app->window, &(app->window_size_x), &(app->window_size_y));
}

void getTextureSize(SDL_Texture *texture, int *w, int *h) {
    if ((w == NULL) || (h == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (SDL_QueryTexture(texture, NULL, NULL, w, h) < 0) {
        fprintf(stderr, "Error get_texture_size : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

// Debug functions

void printWindowPos(App *app) {
    int x, y;
    SDL_GetWindowPosition(app->window, &x, &y);
    printf("Window position\n X : %d\n Y : %d\n", x, y);
}

// Useful functions

void setWindowColor(App *app, SDL_Color color) {
    if (SDL_SetRenderDrawColor(app->renderer, color.r, color.g, color.b, color.a) < 0) {
        fprintf(stderr, "Error setWindowColor : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if (SDL_RenderClear(app->renderer) < 0) {
        fprintf(stderr, "Error setWindowColor : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void randomColor(SDL_Color *color) {
    if (color == NULL) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    color->r = rand() % 256;
    color->g = rand() % 256;
    color->b = rand() % 256;
    color->a = 255;
}

SDL_Texture *loadTexture(App *app, const char *path) {
    SDL_Surface *surface = loadSurface(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, surface);
    if (texture == NULL) {
        fprintf(stderr, "Error loadTexture : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Surface *loadSurface(const char *path) {
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (surface == NULL) {
        fprintf(stderr, "Error loadSurface : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return surface;
}

void updatePlayer(Player *player) {
    player->hitbox.x = player->position.x;
    player->hitbox.y = player->position.y;
}
