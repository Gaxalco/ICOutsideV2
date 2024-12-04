#include "main.h"

void HandleInputs(SDL_Event event, Player *player, bool *quit) {
    if (event.type == SDL_QUIT) {
        *quit = true;
    }
    // KEYDOWN
    else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP: player->directionY = -1; break;
            case SDLK_DOWN: player->directionY = 1; break;
            case SDLK_LEFT: player->directionX = -1; break;
            case SDLK_RIGHT: player->directionX = 1; break;
        }
    }
    // KEYUP
    else if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
            *quit = true;
        }
        switch (event.key.keysym.sym) {
            case SDLK_UP: player->directionY = 0; break;
            case SDLK_DOWN: player->directionY = 0; break;
            case SDLK_LEFT: player->directionX = 0; break;
            case SDLK_RIGHT: player->directionX = 0; break;
        }
    }
}

void Move(Player *player, Clock *clock) {
    player->position.x += player->speed * player->directionX * clock->deltaTime;
    player->position.y += player->speed * player->directionY * clock->deltaTime;

    UpdatePlayer(player);
}