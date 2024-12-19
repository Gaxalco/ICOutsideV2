#include "assets/lib/headers/main.h"

int main(int argc, char *argv[]) {
    App app;

    InitSDL();
    InitApp(&app);

    SDL_Color playerColor = {0, 0, 0, 0};

    while (app.quit == false) {
        UpdateClock(&app.clock);

        while (SDL_PollEvent(&app.event)) {
            HandleInputs(&app);
        }

        RandomColor(&playerColor);
        MovePlayer(&app);

        if (app.player.shooting) {
            CreateBullet(&app);
            app.player.shooting = false;
        }
        UpdateBulletList(&app);

        UpdateWindowSize(&app);
        SetWindowColor(&app);
        SetTextureColor(app.player.texture, playerColor);
        SDL_RenderCopy(app.renderer, app.player.texture, NULL, &app.player.hitbox);
        RenderBullets(&app, app.player.bullets);
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