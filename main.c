#include "assets/lib/headers/main.h"

int main(int argc, char *argv[]) {
    App app;

    Bullet bullets[MAX_BULLETS];

    InitSDL();
    InitApp(&app);

    SDL_Color playerColor = {0, 0, 0, 0};

    SDL_Event event;
    bool quit = false;

    while (quit == false) {
        UpdateClock(&app.clock);

        while (SDL_PollEvent(&event)) {
            HandleInputs(event, &player, &quit);
        }

        RandomColor(&playerColor);
        MovePlayer(&app);

        if (player.shooting) {
            CreateBullet(&app, &player, bullets);
        }
        UpdateBulletList(&app, bullets, &clock);

        UpdateWindowSize(&app);
        SetWindowColor(&app);
        SetTextureColor(player.texture, playerColor);
        SDL_RenderCopy(app.renderer, player.texture, NULL, &player.hitbox);
        RenderBullets(&app, bullets);
        UpdateRender(&app);

        // Cap to 60 FPS
        Uint32 frameTime = SDL_GetTicks() - app.clock.LAST;
        if (frameTime < FRAME_DELAY) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    CloseApp(&app);
    return 0;
}