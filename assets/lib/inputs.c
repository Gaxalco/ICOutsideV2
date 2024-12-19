#include "headers/main.h"

void HandleInputs(App *app) {
    if (app->event.type == SDL_QUIT) {
        app->quit = true;
    }
    // KEYDOWN
    else if (app->event.type == SDL_KEYDOWN && app->event.key.repeat == 0) {
        KeyDown(app);
    }
    // KEYUP
    else if (app->event.type == SDL_KEYUP) {
        KeyUp(app);
    }
}

void KeyDown(App *app) {
    if (app->event.key.keysym.sym == SDLK_UP || app->event.key.keysym.sym == SDLK_z) {
        app->player.directionY = Up;
    }
    if (app->event.key.keysym.sym == SDLK_DOWN || app->event.key.keysym.sym == SDLK_s) {
        app->player.directionY = Down;
    }
    if (app->event.key.keysym.sym == SDLK_LEFT || app->event.key.keysym.sym == SDLK_q) {
        app->player.directionX = Left;
    }
    if (app->event.key.keysym.sym == SDLK_RIGHT || app->event.key.keysym.sym == SDLK_d) {
        app->player.directionX = Right;
    }
    if (app->event.key.keysym.sym == SDLK_SPACE) {
        app->player.shooting = true;
    }
}

void KeyUp(App *app) {
    if (app->event.key.keysym.sym == SDLK_ESCAPE) {
        app->quit = true;
    }
    if (app->event.key.keysym.sym == SDLK_UP || app->event.key.keysym.sym == SDLK_z ||
        app->event.key.keysym.sym == SDLK_DOWN || app->event.key.keysym.sym == SDLK_s ||
        app->event.key.keysym.sym == SDLK_LEFT || app->event.key.keysym.sym == SDLK_q ||
        app->event.key.keysym.sym == SDLK_RIGHT || app->event.key.keysym.sym == SDLK_d) {
        app->player.directionX = Still;
        app->player.directionY = Still;
    }
    if (app->event.key.keysym.sym == SDLK_SPACE) {
        app->player.shooting = false;
    }
}

void MovePlayer(App *app) {

    float normalizedSpeedX = app->player.speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = app->player.speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    if (app->player.directionY == Up) {
        app->player.y -= normalizedSpeedY * app->clock.deltaTime;
    }
    if (app->player.directionY == Down) {
        app->player.y += normalizedSpeedY * app->clock.deltaTime;
    }
    if (app->player.directionX == Left) {
        app->player.x -= normalizedSpeedX * app->clock.deltaTime;
    }
    if (app->player.directionX == Right) {
        app->player.x += normalizedSpeedX * app->clock.deltaTime;
    }


    UpdatePlayerHitbox(&app->player);
}

void UpdateBulletList(App *app) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (app->player.bullets[i].active) {
            MoveBullet(app, &app->player.bullets[i]);
        }
    }
}

void MoveBullet(App *app, Bullet *bullet) {
    float normalizedSpeedX = bullet->speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = bullet->speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    bullet->x += bullet->direction.x * normalizedSpeedX * app->clock.deltaTime;
    bullet->y += bullet->direction.y * normalizedSpeedY * app->clock.deltaTime;

    UpdateBulletHitbox(bullet);
}

void CreateBullet(App *app) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!app->player.bullets[i].active) {
            InitBullet(app, &app->player, &app->player.bullets[i]);
            return;
        }
    }
}