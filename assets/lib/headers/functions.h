#include "main.h"

// Function declarations
/* Init functions */
void InitSDL();
void InitRandom();
void InitApp(App *app);
void InitPlayer(App *app, Player *player);
void InitBullet(App *app, Player *player, Bullet *bullet);
void QuitSDL();
void CloseApp(App *app);
void DeactivatePlayers(Player *players);

/* Useful small functions */
void Delay(unsigned int ms);
bool PointInRect(SDL_Point *P, SDL_Rect *R);
bool Intersect(SDL_Rect *A, SDL_Rect *B);
bool IntersectResult(SDL_Rect *A, SDL_Rect *B, SDL_Rect *Intersection);

/* Getters */
void UpdateWindowSize(App *app);
void GetTextureSize(SDL_Texture *texture, int *w, int *h);

/* Debug functions */
void PrintWindowPos(App *app);

/* Render functions */
void RenderBullets(App *app, Bullet *bullets);

/* Useful functions */
void SetWindowColor(App *app);
void RandomColor(SDL_Color *color);
SDL_Texture *LoadTexture(App *app, const char *path);
SDL_Surface *LoadSurface(const char *path);
void UpdatePlayerHitbox(Player *player);
void HandleInputs(App *app);
void MovePlayer(App *app);
void KeyDown(App *app);
void KeyUp(App *app);
void SetTextureColor(SDL_Texture *texture, SDL_Color color);
void CreateBullet(App *app);
void MoveBullet(App *app, Bullet *bullet);
void UpdateBulletHitbox(Bullet *bullet);
void UpdateRender(App *app);
void UpdateClock(Clock *clock);
void UpdateBulletList(App *app);
void InitBulletList(Bullet *bullets);
void ButtonDown(App *app);
void DeactivateBullet(Bullet *bullet);