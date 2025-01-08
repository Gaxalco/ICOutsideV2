#include "headers/main.h"

void MovePlayer(App *app) {
    float normalizedSpeedX = app->players[0].speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = app->players[0].speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    float newX = app->players[0].x + app->players[0].dx * normalizedSpeedX * app->clock.deltaTime;
    float newY = app->players[0].y + app->players[0].dy * normalizedSpeedY * app->clock.deltaTime;

    // Define screen borders
    int leftBorder = app->windowWidth/7;
    int rightBorder = app->windowWidth - app->windowWidth/7 - app->players[0].hitbox.w;
    int topBorder = app->windowHeight/7;
    int bottomBorder = app->windowHeight - app->windowHeight/7 - app->players[0].hitbox.h;

    // Check if the player is touching any of the screen borders
    bool touchingLeftBorder = newX < leftBorder;
    bool touchingRightBorder = newX > rightBorder;
    bool touchingTopBorder = newY < topBorder;
    bool touchingBottomBorder = newY > bottomBorder;

    if (touchingLeftBorder || touchingRightBorder || touchingTopBorder || touchingBottomBorder) {
        // Move the camera instead of the player
        CameraMovement(app, app->players[0].dx * normalizedSpeedX * app->clock.deltaTime, app->players[0].dy * normalizedSpeedY * app->clock.deltaTime);
    } else {
        // Move the player
        app->players[0].x = newX;
        app->players[0].y = newY;
    }

    UpdatePlayerHitbox(&app->players[0]);
}


void MoveBullet(App *app, Bullet *bullet) {
    float normalizedSpeedX = bullet->speed * ((float)REFERENCE_WIDTH / app->windowWidth);
    float normalizedSpeedY = bullet->speed * ((float)REFERENCE_HEIGHT / app->windowHeight);

    bullet->x += bullet->dx * normalizedSpeedX * app->clock.deltaTime;
    bullet->y += bullet->dy * normalizedSpeedY * app->clock.deltaTime;

    UpdateBulletHitbox(bullet);
}

void CameraMovement(App *app, float dx, float dy) {
    app->players[0].camera.x += dx;
    app->players[0].camera.y += dy;
}