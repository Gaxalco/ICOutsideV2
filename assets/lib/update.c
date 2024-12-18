#include "headers/main.h"

void UpdateRender(App *app) {
    SDL_RenderPresent(app->renderer);
}

void UpdatePlayerHitbox(Player *player) {
    player->hitbox.x = player->x;
    player->hitbox.y = player->y;
}

void UpdateBulletHitbox(Bullet *bullet) {
    bullet->hitbox.x = bullet->x;
    bullet->hitbox.y = bullet->y;
}

void UpdateWindowSize(App *app) {
    SDL_GetWindowSize(app->window, &(app->windowWidth), &(app->windowHeight));
}