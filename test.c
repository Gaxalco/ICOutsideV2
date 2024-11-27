#include "assets/lib/lib.c"

int main(int argc, char *argv[]) {
    App app;
    Player player;
    init_SDL();
    init_APP(&app);
    init_Player(&app, &player);


    SDL_Color cyan = {255, 255, 0, 0};

    SDL_Event e;
    bool quit = false;

    while (quit == false) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }
        randomColor(&cyan);
        setWindowColor(&app, cyan);
        SDL_RenderCopy(app.renderer, player.texture, NULL, &player.hitbox);
        update(&app);
        delay(1);
    }


    close_APP(&app);
    return 0;
}

