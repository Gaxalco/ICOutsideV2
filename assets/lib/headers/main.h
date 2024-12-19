#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define REFERENCE_WIDTH 1920
#define REFERENCE_HEIGHT 1080

#define FRAME_RATE 60
#define FRAME_DELAY (1000 / FRAME_RATE)

#define MAX_BULLETS 100
#define BULLET_SPEED 2.0


#include "structs.h"
#include "enums.h"
#include "functions.h"


extern char *paths[AllPaths];


#endif // MAIN_H