#include "assets/lib/headers/main.h"

int main(int argc, char *argv[]) {
    App app;
    Player player;
    Clock clock;

    Bullet bullets[MAX_BULLETS];

    clock.deltaTime = 0;
    clock.NOW = SDL_GetPerformanceCounter();
    clock.LAST = 0;

    InitSDL();
    InitApp(&app);
    InitPlayer(&app, &player);
    InitBulletList(bullets);

    SDL_Color backGround = {230, 160, 160, 0};
    SDL_Color playerColor = {0, 0, 0, 0};

    SDL_Event event;
    bool quit = false;

    while (quit == false) {
        clock.LAST = clock.NOW;
        clock.NOW = SDL_GetPerformanceCounter();
        clock.deltaTime = (double)((clock.NOW - clock.LAST) * 1000.0 / (double)SDL_GetPerformanceFrequency());

        while (SDL_PollEvent(&event)) {
            HandleInputs(event, &player, &quit);
        }

        RandomColor(&playerColor);
        MovePlayer(&app, &player, &clock);

        if (player.shooting) {
            CreateBullet(&app, &player, bullets);
        }
        UpdateBulletList(&app, bullets, &clock);

        UpdateWindowSize(&app);
        SetWindowColor(&app, backGround);
        SetTextureColor(player.texture, playerColor);
        SDL_RenderCopy(app.renderer, player.texture, NULL, &player.hitbox);
        RenderBullets(&app, bullets);
        UpdateRender(&app);

        // Cap to 60 FPS
        Uint32 frameTime = SDL_GetTicks() - clock.LAST;
        if (frameTime < FRAME_DELAY) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    CloseApp(&app);
    return 0;
}