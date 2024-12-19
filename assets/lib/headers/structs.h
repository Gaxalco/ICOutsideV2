#include "main.h"


// Structs
typedef struct {
    float x;
    float y;

    SDL_Point direction;

    float speed;
    int damage;

    SDL_Rect hitbox;
    SDL_Texture *texture;

    bool active;
} Bullet;


typedef struct {
    SDL_Rect hitbox;

    SDL_Texture *texture;

    float x;
    float y;

    int offsetX;
    int offsetY;

    float speed;

    short directionX;
    short directionY;

    int health;
    int armor;

    int ammo;
    int maxAmmo;

    bool shooting;

    Bullet bullets[MAX_BULLETS];
} Player;

typedef struct {
    double deltaTime;
    Uint64 NOW;
    Uint64 LAST;
} Clock;


typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *icon;
    SDL_Color windowColor;

    int windowWidth;
    int windowHeight;

    Player player;

    Clock clock;

    SDL_Event event;

    bool quit;
} App;