#include "main.h"

void UpdateRender(App *app) {
    SDL_RenderPresent(app->renderer);
}

void UpdatePlayer(Player *player) {
    player->hitbox.x = player->x;
    player->hitbox.y = player->y;
}

void UpdateWindowSize(App *app) {
    SDL_GetWindowSize(app->window, &(app->windowWidth), &(app->windowHeight));
}