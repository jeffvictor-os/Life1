#include <stdio.h>
#include <stdlib.h>
#include "life.h"

// Global ptr array to maps.
// There is always a "current" map which is the current state of life,
//  and a "next" map which is the working area for the next generation.
//  After calculation of the next generation is complete, the pointer
//  to the current map is switched to point to the next-gen map, and
//  vice versa.
//  At the beginning, "currmap" points to map1, and "nextmap" points to map2.
char *map1[DIM];
char *map2[DIM];
char *currmap[DIM];
char *nextmap[DIM];


