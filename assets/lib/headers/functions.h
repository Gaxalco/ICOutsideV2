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

/* Useful functions */
void SetWindowColor(App *app, SDL_Color color);
void RandomColor(SDL_Color *color);
SDL_Texture *LoadTexture(App *app, const char *path);
SDL_Surface *LoadSurface(const char *path);
void UpdatePlayerHitbox(Player *player);
void HandleInputs(SDL_Event event, Player *player, bool *quit);
void MovePlayer(App *app, Player *player, Clock *clock);
void KeyDown(SDL_Event event, Player *player);
void KeyUp(SDL_Event event, Player *player, bool *quit);
void SetTextureColor(SDL_Texture *texture, SDL_Color color);
void CreateBullet(App *app, Player *player, Bullet *bullets);
void MoveBullet(App *app, Bullet *bullet, Clock *clock);
void UpdateBulletHitbox(Bullet *bullet);
void UpdateRender(App *app);
void DrawPoint(App *app, SDL_Point *point);
void DrawLine(App *app, SDL_Point *point1, SDL_Point *point2);
void DrawRect(App *app, SDL_Rect *rect, bool fill);
void UpdateBulletList(App *app, Bullet *bullets, Clock *clock);
void RenderBullets(App *app, Bullet *bullets);
void InitBulletList(Bullet *bullets);