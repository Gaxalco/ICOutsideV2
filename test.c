#include "assets/lib/main.h"

int main(int argc, char *argv[]) {
    App app;
    Player player;
    Clock clock;

    clock.deltaTime = 0;
    clock.NOW = SDL_GetPerformanceCounter();
    clock.LAST = 0;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

    initSDL();
    initApp(&app);
    initPlayer(&app, &player);

    SDL_Color cyan = {255, 255, 0, 0};

    SDL_Event event;
    bool quit = false;

    while (quit == false) {

        clock.LAST = clock.NOW;
        clock.NOW = SDL_GetPerformanceCounter();
        clock.deltaTime = (double)((clock.NOW - clock.LAST) / (double)SDL_GetPerformanceFrequency());

        while (SDL_PollEvent(&event)) {
            handleInputs(event, &player, &clock, &quit);
        }
        //randomColor(&cyan);
        setWindowColor(&app, cyan);
        updatePlayer(&player);
        SDL_RenderCopy(app.renderer, player.texture, NULL, &player.hitbox);
        updateApp(&app);
    }

    closeApp(&app);
    return 0;
}
