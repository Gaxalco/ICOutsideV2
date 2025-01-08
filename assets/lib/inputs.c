#include "headers/main.h"

void HandleInputs(App *app) {
    if (app->event.type == SDL_QUIT) {
        app->quit = true;
    }
    // KEYDOWN
    else if (app->event.type == SDL_KEYDOWN && app->event.key.repeat == 0) {
        KeyDown(app);
    }
    // BUTTONDOWN
    else if (app->event.type == SDL_MOUSEBUTTONDOWN) {
        ButtonDown(app);
    }
    // KEYUP
    else if (app->event.type == SDL_KEYUP) {
        KeyUp(app);
    }
}

void KeyDown(App *app) {
    if (app->event.key.keysym.sym == SDLK_UP || app->event.key.keysym.sym == SDLK_z) {
        app->players[0].dy += -1;
    }
    if (app->event.key.keysym.sym == SDLK_DOWN || app->event.key.keysym.sym == SDLK_s) {
        app->players[0].dy += 1;
    }
    if (app->event.key.keysym.sym == SDLK_LEFT || app->event.key.keysym.sym == SDLK_q) {
        app->players[0].dx += -1;
    }
    if (app->event.key.keysym.sym == SDLK_RIGHT || app->event.key.keysym.sym == SDLK_d) {
        app->players[0].dx += 1;
    }
}

void ButtonDown(App *app) {
    if (app->event.button.button == SDL_BUTTON_LEFT) {
        app->players[0].shooting = true;
    }
}

void KeyUp(App *app) {
    if (app->event.key.keysym.sym == SDLK_ESCAPE) {
        app->quit = true;
    }
   if (app->event.key.keysym.sym == SDLK_UP || app->event.key.keysym.sym == SDLK_z) {
        app->players[0].dy += 1;
    }
    if (app->event.key.keysym.sym == SDLK_DOWN || app->event.key.keysym.sym == SDLK_s) {
        app->players[0].dy += -1;
    }
    if (app->event.key.keysym.sym == SDLK_LEFT || app->event.key.keysym.sym == SDLK_q) {
        app->players[0].dx += 1;
    }
    if (app->event.key.keysym.sym == SDLK_RIGHT || app->event.key.keysym.sym == SDLK_d) {
        app->players[0].dx += -1;
    }
}