#include "life.h"

int CopyUniverse() {
  int r=0, c=0;
  
  for (r=1; r<=DIM; r++)
    for (c=1; c<=DIM; c++)
      currmap[r][c] = nextmap[r][c];
}




