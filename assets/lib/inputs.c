#include "headers/main.h"

void HandleInputs(App *app) {
    if (app->event.type == SDL_QUIT) {
        app->quit = true;
    }
    // KEYDOWN
    else if (app->event.type == SDL_KEYDOWN && app->event.key.repeat == 0) {
        KeyDown(app);
    }
    // BUTTONDOWN
    else if (app->event.type == SDL_MOUSEBUTTONDOWN) {
        ButtonDown(app);
    }
    // KEYUP
    else if (app->event.type == SDL_KEYUP) {
        KeyUp(app);
    }
}

void KeyDown(App *app) {
    if (app->event.key.keysym.sym == SDLK_UP || app->event.key.keysym.sym == SDLK_z) {
        app->players[0].dy += -1;
    }
    if (app->event.key.keysym.sym == SDLK_DOWN || app->event.key.keysym.sym == SDLK_s) {
        app->players[0].dy += 1;
    }
    if (app->event.key.keysym.sym == SDLK_LEFT || app->event.key.keysym.sym == SDLK_q) {
        app->players[0].dx += -1;
    }
    if (app->event.key.keysym.sym == SDLK_RIGHT || app->event.key.keysym.sym == SDLK_d) {
        app->players[0].dx += 1;
    }
}

void ButtonDown(App *app) {
    if (app->event.button.button == SDL_BUTTON_LEFT) {
        app->players[0].shooting = true;
    }
}

void KeyUp(App *app) {
    if (app->event.key.keysym.sym == SDLK_ESCAPE) {
        app->quit = true;
    }
   if (app->event.key.keysym.sym == SDLK_UP || app->event.key.keysym.sym == SDLK_z) {
        app->players[0].dy += 1;
    }
    if (app->event.key.keysym.sym == SDLK_DOWN || app->event.key.keysym.sym == SDLK_s) {
        app->players[0].dy += -1;
    }
    if (app->event.key.keysym.sym == SDLK_LEFT || app->event.key.keysym.sym == SDLK_q) {
        app->players[0].dx += 1;
    }
    if (app->event.key.keysym.sym == SDLK_RIGHT || app->event.key.keysym.sym == SDLK_d) {
        app->players[0].dx += -1;
    }
}

void MovePlayer(App *app) {

    float normalizedSpeedX = app->players[0].speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = app->players[0].speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    if ((app->players[0].x < app->windowWidth / 2 - CAMERA_WIDTH) / 2 || (app->players[0].x > app->windowWidth / 2 + CAMERA_WIDTH / 2) || (app->players[0].y < app->windowHeight / 2 - CAMERA_HEIGHT / 2) || (app->players[0].y > app->windowHeight / 2 + CAMERA_HEIGHT / 2)) {
        // Move camera
        if (app->players[0].x < app->windowWidth / 2 - CAMERA_WIDTH / 2 && app->players[0].dx == -1) {
            app->players[0].camera.x += app->players[0].dx * normalizedSpeedX * app->clock.deltaTime;;
        } else if (app->players[0].x > app->windowWidth / 2 + CAMERA_WIDTH / 2 && app->players[0].dx == 1) {
            app->players[0].camera.x += app->players[0].dx * normalizedSpeedX * app->clock.deltaTime;;
        }
        if (app->players[0].y < app->windowHeight / 2 - CAMERA_HEIGHT / 2 && app->players[0].dy == -1) {
            app->players[0].camera.y += -app->players[0].dy * normalizedSpeedY * app->clock.deltaTime;
        } else if (app->players[0].y > app->windowHeight / 2 + CAMERA_HEIGHT / 2 && app->players[0].dy == 1) {
            app->players[0].camera.y += -app->players[0].dy * normalizedSpeedY * app->clock.deltaTime;
        }
    } else {
        app->players[0].x += app->players[0].dx * normalizedSpeedX * app->clock.deltaTime;
        app->players[0].y += app->players[0].dy * normalizedSpeedY * app->clock.deltaTime;
    }
    UpdatePlayerHitbox(&app->players[0]);
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

void MoveBullet(App *app, Bullet *bullet) {
    float normalizedSpeedX = bullet->speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = bullet->speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    bullet->x += bullet->dx * normalizedSpeedX * app->clock.deltaTime;
    bullet->y += bullet->dy * normalizedSpeedY * app->clock.deltaTime;

    UpdateBulletHitbox(bullet);
}

void CreateBullet(App *app) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!app->players[0].bullets[i].active) {
            InitBullet(app, &app->players[0], &app->players[0].bullets[i]);
            return;
        }
    }
}