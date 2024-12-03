#include "main.h"


void initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error SDL_Init : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

// CALL ONLY ONCE
void initRandom() {
    srand(time(NULL));
}

void initApp(App *app) {
    if (app != NULL) {
        fprintf(stderr, "WARNING! app is not NULL\n");
    }
    app->window_size_x = 1920;
    app->window_size_y = 1080;

    app->window = SDL_CreateWindow("ICOutside", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    app->window_size_x, app->window_size_y, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (app->window == NULL) {
        fprintf(stderr, "Failed to initialise Window : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (app->renderer == NULL) {
        fprintf(stderr, "Failed to initialise Renderer : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    app->icon = loadSurface(paths[Icon]);
    SDL_SetWindowIcon(app->window, app->icon);

    // Ensure that the window is in front of all the others
    SDL_RaiseWindow(app->window);
}

// Init Player
void initPlayer(App *app, Player *player) {
    if (player != NULL) {
        fprintf(stderr, "WARNING! player is not NULL\n");
    }
    player->speed = 100000;
    player->texture = loadTexture(app, paths[Kungfu]);
    getTextureSize(player->texture, &(player->hitbox.w), &(player->hitbox.h));
    player->position.x = app->window_size_x / 2 - player->hitbox.w / 2;
    player->position.y = app->window_size_y / 2 - player->hitbox.h / 2;
    player->hitbox.x = app->window_size_x / 2 - player->hitbox.w / 2;
    player->hitbox.y = app->window_size_y / 2 - player->hitbox.h / 2;

    player->normalizedSpeedX = player->speed * (REFERENCE_WIDTH / (float)app->window_size_x);
    player->normalizedSpeedY = player->speed * (REFERENCE_HEIGHT / (float)app->window_size_y);
}

void quitSDL() {
    SDL_Quit();
}

void closeApp(App *app) {
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->renderer);
    app->renderer = NULL;
    app->window = NULL;
    quitSDL();
}