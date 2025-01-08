#include "headers/main.h"

void MovePlayer(App *app) {
    float normalizedSpeedX = app->players[0].speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = app->players[0].speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    app->players[0].x += app->players[0].dx * normalizedSpeedX * app->clock.deltaTime;
    app->players[0].y += app->players[0].dy * normalizedSpeedY * app->clock.deltaTime;
    
    UpdatePlayerHitbox(&app->players[0]);
}


void MoveBullet(App *app, Bullet *bullet) {
    float normalizedSpeedX = bullet->speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = bullet->speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    bullet->x += bullet->dx * normalizedSpeedX * app->clock.deltaTime;
    bullet->y += bullet->dy * normalizedSpeedY * app->clock.deltaTime;

    UpdateBulletHitbox(bullet);
}

void CameraMovement(App *app) {
    float normalizedSpeedX = app->players[0].speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = app->players[0].speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    app->players[0].camera.x += app->players[0].dx * normalizedSpeedX * app->clock.deltaTime;
    app->players[0].camera.y += app->players[0].dy * normalizedSpeedY * app->clock.deltaTime;
}