#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "structs.c"


// Basic Init and Quit functions

void init_SDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error SDL_Init : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void init_APP(App *app) {
    if (app != NULL) {
        fprintf(stderr, "WARNING! app is not NULL\n");
    }
    app->window_size_x = 640;
    app->window_size_y = 480;

    app->window = SDL_CreateWindow("ICOutside", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    app->window_size_x, app->window_size_y, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (app->window == NULL) {
        fprintf(stderr, "Failed to initialise Window : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);


    // Ensure that the window is in front of all the others
    SDL_RaiseWindow(app->window);
}

void quit_SDL() {
    SDL_Quit();
}

void close_APP(App *app) {
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
    app->renderer;
    app->window = NULL;
    quit_SDL();
}


// Usefull small functions

void delay(unsigned int ms) {
    SDL_Delay(ms);
}

bool pointInRect(SDL_Point *P, SDL_Rect *R) {
    if ((P ==  NULL) | (R == NULL)) {
        fprintf(stderr, "Pointer is NULL!");
        exit(EXIT_FAILURE);
    }
    return SDL_PointInRect(P, R);
}

bool intersect(SDL_Rect *A, SDL_Rect *B) {
    if ((A ==  NULL) | (B == NULL)) {
        fprintf(stderr, "Pointer is NULL!");
        exit(EXIT_FAILURE);
    }
    return SDL_HasIntersection(A, B);
}

bool intersectResult(SDL_Rect *A, SDL_Rect *B, SDL_Rect *Intersection) {
    if ((A ==  NULL) | (B == NULL)) {
        fprintf(stderr, "Pointer is NULL!");
        exit(EXIT_FAILURE);
    }
    return SDL_IntersectRect(A, B, Intersection);
}

// Getters

void update_window_size(App *app) {
    SDL_GetWindowSize(app->window, &(app->window_size_x), &(app->window_size_y));
}


// Debug functions

void print_window_pos(App *app) {
    int x, y;
    SDL_GetWindowPosition(app->window, &x, &y);
    printf("Window position\n X : %d\n Y : %d", x, y);
}