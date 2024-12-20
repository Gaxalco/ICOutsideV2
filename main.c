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


        UpdateBulletList(&app);

        UpdateWindowSize(&app);
        SetWindowColor(&app);
        SetTextureColor(app.players[0].texture, playerColor);
        SDL_RenderCopy(app.renderer, app.players[0].texture, NULL, &app.players[0].hitbox);
        RenderBullets(&app, app.players[0].bullets);
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