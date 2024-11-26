#include "lib.c"

int main(int argc, char *argv[]) {
    App app;
    init_SDL();
    init_APP(&app);

    SDL_Rect rect1 = {100, 100, 50, 50};
    SDL_Rect rect2 = {120, 120, 50, 50};
    SDL_Rect rect3 = {200, 200, 50, 50};

    printf("Intersection between rect1 and rect2: %s\n", intersect(&rect1, &rect2) ? "true" : "false");
    printf("Intersection between rect1 and rect3: %s\n", intersect(&rect1, &rect3) ? "true" : "false");

    close_APP(&app);
    return 0;
}

