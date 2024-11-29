#include "assets/lib/lib.c"

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
        clock.deltaTime = (double)((clock.NOW - clock.LAST) / (double)SDL_GetPerformanceFrequency()); // Copilot says "remove * 1000"

        while (SDL_PollEvent(&event)) {
            // Quit event
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            // KEYDOWN
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_z) {
                    player.position.y -= player.speed * clock.deltaTime;
                }
                if (event.key.keysym.sym == SDLK_q) {
                    player.position.x -= player.speed * clock.deltaTime;
                }
                if (event.key.keysym.sym == SDLK_s) {
                    player.position.y += player.speed * clock.deltaTime;
                }
                if (event.key.keysym.sym == SDLK_d) {
                    player.position.x += player.speed * clock.deltaTime;
                }
            }
            // KEYUP
            else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                }
            }
            
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
