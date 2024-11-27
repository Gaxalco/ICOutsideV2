#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "structs.c"



// Declarations of all functions

/* Init functions */
void init_SDL();
void init_random();
void init_APP(App *app);
void init_Player(App *app, Player *player);
void quit_SDL();
void close_APP(App *app);

/* Usefull small functions */
void delay(unsigned int ms);
bool pointInRect(SDL_Point *P, SDL_Rect *R);
bool intersect(SDL_Rect *A, SDL_Rect *B);
bool intersectResult(SDL_Rect *A, SDL_Rect *B, SDL_Rect *Intersection);
void update(App *app);
void drawPoint(App *app, SDL_Point *point);
void drawLine(App *app, SDL_Point *point1, SDL_Point *point2);
void drawRect(App *app, SDL_Rect *rect, bool fill);

/* Getters */
void update_window_size(App *app);
void get_texture_size(SDL_Texture *texture, int *w, int *h);

/* Debug functions */
void print_window_pos(App *app);

/* Usefull functions */
void setWindowColor(App *app, SDL_Color color);
void randomColor(SDL_Color *color);
SDL_Texture *loadTexture(App *app, const char *path);
SDL_Surface *loadSurface(const char *path);





// Basic Init and Quit functions

void init_SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error SDL_Init : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

// CALL ONLY ONCE
void init_random() {
    srand(time(NULL));
}

void init_APP(App *app) {
    if (app != NULL) {
        fprintf(stderr, "WARNING! app is not NULL\n");
    }
    app->window_size_x = 1920;
    app->window_size_y = 1080;

    app->window = SDL_CreateWindow("ICOutside", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    app->window_size_x, app->window_size_y, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (app->window == NULL) {
        fprintf(stderr, "Failed to initialise Window : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (app->renderer == NULL) {
        fprintf(stderr, "Failed to initialise Renderer : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    app->icon = loadSurface(paths[Icon]);
    SDL_SetWindowIcon(app->window, app->icon);


    // Ensure that the window is in front of all the others
    SDL_RaiseWindow(app->window);
}

// Init Player
void init_Player(App *app, Player *player) {
    if (player != NULL) {
        fprintf(stderr, "WARNING! player is not NULL\n");
    }
    player->texture = loadTexture(app, paths[Kungfu]);
    get_texture_size(player->texture, &(player->hitbox.w), &(player->hitbox.h));
    player->position.x = app->window_size_x / 2 - player->hitbox.w / 2;
    player->position.y = app->window_size_y / 2 - player->hitbox.h / 2;
    player->hitbox.x = app->window_size_x / 2 - player->hitbox.w / 2;
    player->hitbox.y = app->window_size_y / 2 - player->hitbox.h / 2;
}

void quit_SDL() {
    SDL_Quit();
}

void close_APP(App *app) {
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
    app->renderer = NULL;
    app->window = NULL;
    quit_SDL();
}


// Usefull small functions

void delay(unsigned int ms) {
    SDL_Delay(ms);
}

bool pointInRect(SDL_Point *P, SDL_Rect *R) {
    if ((P ==  NULL) | (R == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_PointInRect(P, R);
}

bool intersect(SDL_Rect *A, SDL_Rect *B) {
    if ((A ==  NULL) | (B == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_HasIntersection(A, B);
}

bool intersectResult(SDL_Rect *A, SDL_Rect *B, SDL_Rect *Intersection) {
    if ((A ==  NULL) | (B == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_IntersectRect(A, B, Intersection);
}

void update(App *app) {
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
    if ((point1 == NULL) | (point2 == NULL)) {
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

void update_window_size(App *app) {
    SDL_GetWindowSize(app->window, &(app->window_size_x), &(app->window_size_y));
}

void get_texture_size(SDL_Texture *texture, int *w, int *h) {
    if ((w == NULL) | (h == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    if (SDL_QueryTexture(texture, NULL, NULL, w, h) < 0) {
        fprintf(stderr, "Error get_texture_size : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}


// Debug functions

void print_window_pos(App *app) {
    int x, y;
    SDL_GetWindowPosition(app->window, &x, &y);
    printf("Window position\n X : %d\n Y : %d\n", x, y);
}


// Usefull functions

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