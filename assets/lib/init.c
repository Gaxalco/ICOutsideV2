#include "headers/main.h"


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

    // Set window color
    app->windowColor.r = 230;
    app->windowColor.g = 160;
    app->windowColor.b = 160;
    app->windowColor.a = 0;

    // Init clock
    app->clock.deltaTime = 0;
    app->clock.NOW = SDL_GetPerformanceCounter();
    app->clock.LAST = 0;

    // Deactivate players
    DeactivatePlayers(app->players);
    InitPlayer(app, &(app->players[0]));

    // Update window size
    UpdateWindowSize(app);

    app->quit = false;
}

// Init Player
void InitPlayer(App *app, Player *player) {
    if (player != NULL) {
        fprintf(stderr, "WARNING! player is not NULL\n");
    }

    player->active = true;
    player->speed = 1;
    player->health = 100;
    player->armor = 0;
    player->ammo = MAX_BULLETS;
    player->maxAmmo = MAX_BULLETS;

    player->texture = LoadTexture(app, paths[Kungfu]);
    GetTextureSize(player->texture, &(player->hitbox.w), &(player->hitbox.h));
    player->x = app->windowWidth / 2 - player->hitbox.w / 2;
    player->y = app->windowHeight / 2 - player->hitbox.h / 2;
    player->hitbox.x = app->windowWidth / 2 - player->hitbox.w / 2;
    player->hitbox.y = app->windowHeight / 2 - player->hitbox.h / 2;
    player->dx = 0;
    player->dy = 0;
    // Init bullets
    InitBulletList(player->bullets);


    // Ensure window size is updated
    UpdateWindowSize(app);
}

void InitBulletList(Bullet *bullets) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = false;
    }
}

void InitBullet(App *app, Player *player, Bullet *bullet) {
    bullet->active = true;
    bullet->x = player->x + player->hitbox.w / 2;
    bullet->y = player->y + player->hitbox.h / 2;
    bullet->speed = BULLET_SPEED;
    bullet->damage = 1;
    bullet->texture = LoadTexture(app, paths[Kungfu]);
    bullet->hitbox.w = 50;
    bullet->hitbox.h = 50;
    bullet->hitbox.x = bullet->x;
    bullet->hitbox.y = bullet->y;

    // Set direction
    SDL_Point mousePos;
    SDL_GetMouseState(&mousePos.x, &mousePos.y);
    // Calculate distance between player and mouse
    float distance = sqrt(pow(mousePos.x - bullet->x, 2) + pow(mousePos.y - bullet->y, 2));
    bullet->dx = (mousePos.x - bullet->x) / distance;
    bullet->dy = (mousePos.y - bullet->y) / distance;
}

void DeactivatePlayers(Player *players) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].active = false;
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