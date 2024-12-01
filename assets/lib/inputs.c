#include "main.h"

void handleInputs(SDL_Event event, Player *player, Clock *clock, bool *quit) {
    if (event.type == SDL_QUIT) {
        *quit = true;
    }
    // KEYDOWN
    else if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_z) {
            player->position.y -= player->speed * clock->deltaTime;
        }
        if (event.key.keysym.sym == SDLK_q) {
            player->position.x -= player->speed * clock->deltaTime;
        }
        if (event.key.keysym.sym == SDLK_s) {
            player->position.y += player->speed * clock->deltaTime;
        }
        if (event.key.keysym.sym == SDLK_d) {
            player->position.x += player->speed * clock->deltaTime;
        }
    }
    // KEYUP
    else if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
            *quit = true;
        }
    }
}