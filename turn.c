// turn.c: the "core" function of this program.
// It computes the result of life and death.
// The primary function is Turn(). Supporting routines are
// also in here.

#include <stdio.h>

#include "life.h"

//The basic logic is:
// For each location:
//  Detect and sum the living neighbors of this location.
//  Based on the sum, this location will be alive or empty next turn. 
//  Store that result.

int Turn() {
  int row=0, col=0, naybors=0;

  for (row=0; row<DIM; row++) {
    for (col=0; col<DIM; col++) {
    naybors = CountNaybors (p_currmap, row, col);

    if (p_currmap[row][col] == ALIVE)
      if (naybors<2 || naybors>3) 
        p_nextmap[row][col] = EMPTY;
      else
        p_nextmap[row][col] = ALIVE;
    else 
      if (naybors == 3)
        p_nextmap[row][col] = ALIVE;
      else
        p_nextmap[row][col] = EMPTY;
    }
  }
}


