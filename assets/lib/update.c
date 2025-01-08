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

void UpdateClock(Clock *clock) {
    clock->LAST = clock->NOW;
    clock->NOW = SDL_GetPerformanceCounter();
    clock->deltaTime = (double)((clock->NOW - clock->LAST) * 1000.0 / (double)SDL_GetPerformanceFrequency());
}



void UpdateBulletList(App *app) {
    if (app->players[0].shooting) {
        CreateBullet(app);
        app->players[0].shooting = false;
    }
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (app->players[0].bullets[i].active) {
            // Bullet out of screen
            if (app->players[0].bullets[i].x < 0 || app->players[0].bullets[i].x > app->windowWidth || app->players[0].bullets[i].y < 0 || app->players[0].bullets[i].y > app->windowHeight) {
                DeactivateBullet(&app->players[0].bullets[i]);
            } else {
                MoveBullet(app, &app->players[0].bullets[i]);
            }
        }
    }
}