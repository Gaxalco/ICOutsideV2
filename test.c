#include "assets/lib/main.h"

int main(int argc, char *argv[]) {
    App app;
    Player player;
    Clock clock;

    clock.deltaTime = 0;
    clock.NOW = SDL_GetPerformanceCounter();
    clock.LAST = SDL_GetPerformanceCounter();

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

    initSDL();
    initApp(&app);
    initPlayer(&app, &player);

    SDL_Color rose = {230, 160, 160, 0};

    SDL_Event event;
    bool quit = false;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    while (quit == false) {
        Uint32 frameStart = SDL_GetTicks();

        clock.LAST = clock.NOW;
        clock.NOW = SDL_GetPerformanceCounter();
        clock.deltaTime = (double)((clock.NOW - clock.LAST) / (double)SDL_GetPerformanceFrequency());

        while (SDL_PollEvent(&event)) {
            handleInputs(event, &player, &clock, &quit);
        }

        setWindowColor(&app, rose);
        updatePlayer(&player);
        SDL_RenderCopy(app.renderer, player.texture, NULL, &player.hitbox);
        updateApp(&app);

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    closeApp(&app);
    return 0;
}