#include "assets/lib/lib.c"

int main(int argc, char *argv[]) {
    App app;
    Player player;

    double deltaTime = 0;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    init_SDL();
    init_APP(&app);
    init_Player(&app, &player);


    SDL_Color cyan = {255, 255, 0, 0};

    SDL_Event event;
    bool quit = false;

    while (quit == false) {

        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

        while (SDL_PollEvent(&event)) {
            // Quit event
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            // KEYDOWN
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_z) {
                    player.position.y -= player.speed * deltaTime;
                }
                if (event.key.keysym.sym == SDLK_q) {
                    player.position.x -= player.speed * deltaTime;
                }
                if (event.key.keysym.sym == SDLK_s) {
                    player.position.y += player.speed * deltaTime;
                }
                if (event.key.keysym.sym == SDLK_d) {
                    player.position.x += player.speed * deltaTime;
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
        update_player(&player);
        SDL_RenderCopy(app.renderer, player.texture, NULL, &player.hitbox);
        update(&app);
    }


    close_APP(&app);
    return 0;
}

