#include "main.h"


void InitSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error SDL_Init : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

// CALL ONLY ONCE
void InitRandom() {
    srand(time(NULL));
}

void InitApp(App *app) {
    if (app != NULL) {
        fprintf(stderr, "WARNING! app is not NULL\n");
    }
    app->windowWidth = REFERENCE_WIDTH;
    app->windowHeight = REFERENCE_HEIGHT;

    app->window = SDL_CreateWindow("ICOutside", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    app->windowWidth, app->windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (app->window == NULL) {
        fprintf(stderr, "Failed to initialise Window : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (app->renderer == NULL) {
        fprintf(stderr, "Failed to initialise Renderer : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    app->icon = LoadSurface(paths[Icon]);
    SDL_SetWindowIcon(app->window, app->icon);

    // Ensure that the window is in front of all the others
    SDL_RaiseWindow(app->window);
    SDL_SetWindowFullscreen(app->window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    // Update window size
    UpdateWindowSize(app);
}

// Init Player
void InitPlayer(App *app, Player *player) {
    if (player != NULL) {
        fprintf(stderr, "WARNING! player is not NULL\n");
    }
    player->speed = 1;
    player->texture = LoadTexture(app, paths[Kungfu]);
    GetTextureSize(player->texture, &(player->hitbox.w), &(player->hitbox.h));
    player->x = app->windowWidth / 2 - player->hitbox.w / 2;
    player->y = app->windowHeight / 2 - player->hitbox.h / 2;
    player->hitbox.x = app->windowWidth / 2 - player->hitbox.w / 2;
    player->hitbox.y = app->windowHeight / 2 - player->hitbox.h / 2;
    player->up = false;
    player->down = false;
    player->left = false;
    player->right = false;

    // Ensure window size is updated
    UpdateWindowSize(app);
}

void InitBullet(App *app, Player *player, Bullet *bullet) {
    if (bullet != NULL) {
        fprintf(stderr, "WARNING! bullet is not NULL\n");
    }
    bullet->active = true;
    bullet->x = player->x + player->hitbox.w / 2;
    bullet->y = player->y + player->hitbox.h / 2;
    bullet->speed = 0.5;
    bullet->damage = 1;
    bullet->texture = LoadTexture(app, paths[Kungfu]);
    bullet->hitbox.w = 50;
    bullet->hitbox.h = 50;
    bullet->hitbox.x = bullet->x;
    bullet->hitbox.y = bullet->y;

    if (player->up) {
        bullet->direction.x = 0;
        bullet->direction.y = -1;
    }
    if (player->down) {
        bullet->direction.x = 0;
        bullet->direction.y = 1;
    }
    if (player->left) {
        bullet->direction.x = -1;
        bullet->direction.y = 0;
    }
    if (player->right) {
        bullet->direction.x = 1;
        bullet->direction.y = 0;
    }
}

void QuitSDL() {
    SDL_Quit();
}

void CloseApp(App *app) {
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
    app->renderer = NULL;
    app->window = NULL;
    QuitSDL();
}