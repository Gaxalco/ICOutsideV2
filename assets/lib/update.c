#include "main.h"

void UpdateRender(App *app) {
    SDL_RenderPresent(app->renderer);
}

void UpdatePlayer(Player *player) {
    player->hitbox.x = player->position.x;
    player->hitbox.y = player->position.y;
}

void UpdateWindowSize(App *app) {
    SDL_GetWindowSize(app->window, &(app->windowWidth), &(app->windowHeight));
}