#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define REFERENCE_WIDTH 1920
#define REFERENCE_HEIGHT 1080

// Enums
typedef enum {
    MAP,
    PLAYER,
    WEAPONS,
    MAP_TOP,
    AllRenderLayers
} RenderLayers;

typedef enum {
    Icon,
    Kungfu,
    AllPaths
} Paths;

extern char *paths[AllPaths];

// Structs
typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *icon;

    int window_size_x;
    int window_size_y;
} App;

typedef struct {
    SDL_Rect hitbox;

    SDL_Point position;
    SDL_Texture *texture;

    int speed;
    float normalizedSpeedX;
    float normalizedSpeedY;

    int health;
    int armor;
    int ammo;
} Player;

typedef struct {
    double deltaTime;
    Uint64 NOW;
    Uint64 LAST;
} Clock;

// Function declarations
/* Init functions */
void initSDL();
void initRandom();
void initApp(App *app);
void initPlayer(App *app, Player *player);
void quitSDL();
void closeApp(App *app);

/* Useful small functions */
void delay(unsigned int ms);
bool pointInRect(SDL_Point *P, SDL_Rect *R);
bool intersect(SDL_Rect *A, SDL_Rect *B);
bool intersectResult(SDL_Rect *A, SDL_Rect *B, SDL_Rect *Intersection);
void updateApp(App *app);
void drawPoint(App *app, SDL_Point *point);
void drawLine(App *app, SDL_Point *point1, SDL_Point *point2);
void drawRect(App *app, SDL_Rect *rect, bool fill);

/* Getters */
void updateWindowSize(App *app);
void getTextureSize(SDL_Texture *texture, int *w, int *h);

/* Debug functions */
void printWindowPos(App *app);

/* Useful functions */
void setWindowColor(App *app, SDL_Color color);
void randomColor(SDL_Color *color);
SDL_Texture *loadTexture(App *app, const char *path);
SDL_Surface *loadSurface(const char *path);
void updatePlayer(Player *player);
void handleInputs(SDL_Event event, Player *player, Clock *clock, bool *quit);

#endif // MAIN_H