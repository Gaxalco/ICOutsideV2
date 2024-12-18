#include "headers/main.h"



bool PointInRect(SDL_Point *P, SDL_Rect *R) {
    if ((P ==  NULL) || (R == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_PointInRect(P, R);
}

bool Intersect(SDL_Rect *A, SDL_Rect *B) {
    if ((A ==  NULL) || (B == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_HasIntersection(A, B);
}

bool IntersectResult(SDL_Rect *A, SDL_Rect *B, SDL_Rect *Intersection) {
    if ((A ==  NULL) || (B == NULL)) {
        fprintf(stderr, "Pointer is NULL!\n");
        exit(EXIT_FAILURE);
    }
    return SDL_IntersectRect(A, B, Intersection);
}