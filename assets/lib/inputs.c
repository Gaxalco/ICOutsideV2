#include "headers/main.h"

void HandleInputs(SDL_Event event, Player *player, bool *quit) {
    if (event.type == SDL_QUIT) {
        *quit = true;
    }
    // KEYDOWN
    else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        KeyDown(event, player);
    }
    // KEYUP
    else if (event.type == SDL_KEYUP) {
        KeyUp(event, player, quit);
    }
}

void KeyDown(SDL_Event event, Player *player) {
    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_z) {
        player->up = true;
    }
    if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
        player->down = true;
    }
    if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_q) {
        player->left = true;
    }
    if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
        player->right = true;
    }
    if (event.key.keysym.sym == SDLK_SPACE) {
        player->shooting = true;
    }
}

void KeyUp(SDL_Event event, Player *player, bool *quit) {
    if (event.key.keysym.sym == SDLK_ESCAPE) {
        *quit = true;
    }
    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_z) {
        player->up = false;
    }
    if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) {
        player->down = false;
    }
    if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_q) {
        player->left = false;
    }
    if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
        player->right = false;
    }
    if (event.key.keysym.sym == SDLK_SPACE) {
        player->shooting = false;
    }
}

void MovePlayer(App *app, Player *player, Clock *clock) {

    float normalizedSpeedX = player->speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = player->speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    if (player->up) {
        player->y -= normalizedSpeedY * clock->deltaTime;
    }   
    if (player->down) {
        player->y += normalizedSpeedY * clock->deltaTime;
    }
    if (player->left) {
        player->x -= normalizedSpeedX * clock->deltaTime;
    }
    if (player->right) {
        player->x += normalizedSpeedX * clock->deltaTime;
    }

    UpdatePlayerHitbox(player);
}

void UpdateBulletList(App *app, Bullet *bullets, Clock *clock) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            MoveBullet(app, &bullets[i], clock);
        }
    }
}

void MoveBullet(App *app, Bullet *bullet, Clock *clock) {
    float normalizedSpeedX = bullet->speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = bullet->speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    bullet->x += bullet->direction.x * normalizedSpeedX * clock->deltaTime;
    bullet->y += bullet->direction.y * normalizedSpeedY * clock->deltaTime;

    UpdateBulletHitbox(bullet);
}

void CreateBullet(App *app, Player *player, Bullet *bullets) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) {
            InitBullet(app, player, &bullets[i]);
            return;
        }
    }
}