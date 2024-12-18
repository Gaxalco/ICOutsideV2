#include "headers/main.h"

void PrintWindowPos(App *app) {
    int x, y;
    SDL_GetWindowPosition(app->window, &x, &y);
    printf("Window position\n X : %d\n Y : %d\n", x, y);
}