#include "main.h"


// Structs
typedef struct Bullet {
    float x;
    float y;

    float dx;
    float dy;

    float speed;
    int damage;

    SDL_Rect hitbox;
    SDL_Texture *texture;

    bool active;
} Bullet;

typedef struct Camera {
    float x;
    float y;
} Camera;


typedef struct Player{
    SDL_Rect hitbox;
    SDL_Texture *texture;
    int offsetX;
    int offsetY;

    Camera camera;

    float x;
    float y;

    float speed;

    short dx;
    short dy;

    int health;
    int armor;

    int ammo;
    int maxAmmo;
    bool shooting;
    Bullet bullets[MAX_BULLETS];

    bool active;
} Player;



typedef struct Clock {
    double deltaTime;
    Uint64 NOW;
    Uint64 LAST;
} Clock;


typedef struct App {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *icon;
    SDL_Color windowColor;

    int windowWidth;
    int windowHeight;

    Player players[4];

    Clock clock;

    SDL_Event event;

    bool quit;
} App;