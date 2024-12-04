#include "assets/lib/main.h"

int main(int argc, char *argv[]) {
    App app;
    Player player;
    Clock clock;

    clock.deltaTime = 0;
    clock.NOW = SDL_GetPerformanceCounter();
    clock.LAST = SDL_GetPerformanceCounter();

    InitSDL();
    InitApp(&app);
    InitPlayer(&app, &player);

    SDL_Color rose = {230, 160, 160, 0};

    SDL_Event event;
    bool quit = false;


    while (quit == false) {

        clock.LAST = clock.NOW;
        clock.NOW = SDL_GetPerformanceCounter();
        clock.deltaTime = (double)((clock.NOW - clock.LAST)*1000 / (double)SDL_GetPerformanceFrequency());

        while (SDL_PollEvent(&event)) {
            HandleInputs(event, &player, &quit);
        }

        Move(&player, &clock);
        printf("Player position : %d %d\n", player.position.x, player.position.y);
        UpdateWindowSize(&app);
        SetWindowColor(&app, rose);
        SDL_RenderCopy(app.renderer, player.texture, NULL, &player.hitbox);
        UpdateRender(&app);
    }

    CloseApp(&app);
    return 0;
}