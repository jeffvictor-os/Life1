#include "life.h"
#include "lifeglobals.h"

// to be the next generation of life.
// These next two functions enable the use of two in-memory maps to 
// 1) remember the current generation of life
// 2) provide a workspace for 
// recording the next generation.
//
// "currmap" points to the map that is the current represenation of 
// the living cells vs. empty locations. 
// "nextmap" points to the map that we're manipulating, preparing it
//
// Routines that check the status must use currmap.
// Routines that change the status must use nextmap.
// This routine should be used after the next generation 
// has been computed.
int SwitchMaps() {
  if (currmap == map1) {
    currmap = map2;
    nextmap = map1;
  } else {
    currmap = map1;
    nextmap = map2;
  }
}

// CopyUniverse copies currmap to nextmap, so that
// nextmap is pointing to a map that is ready to be changed.
// The calling code should use these steps:
// 1. Start: currmap points to the current map, 
//    nextmap points to a map with undetermined state
// 2. copy currmap to nextmap so that both are current.
// 3. compute next generation in nextmap
// 4. call SwitchMaps(), so that currmap points to the new state
// 5. call CopyUniverse() to copy the new state over the old state
// 6. goto (3)
// 
int CopyUniverse() {
  int r=0, c=0;
//printf (" map1=%d, map2=%d.\n", map1, map2);
//printf (" curr=%d, next=%d.\n", currmap, nextmap);
  
  for (r=0; r<DIM; r++) {
    for (c=0; c<DIM; c++) {
      nextmap[r][c] = currmap[r][c];
    }
  }
}

// Count the naybors in the 8 adjacent locations.
int CountNaybors (char *mymap[], int row, int col) {
  int naybors=0, r=0, c=0;

  for (r=row-1; r<=row+1; r++) 
    for (c=col-1; c<=col+1; c++)  
      if (r>=0   && r< DIM &&       // Is in bounds? 
          c>=0   && c< DIM &&       // Is in bounds? 
        !(r==row && c==col) &&      // Not the location itself.
          mymap[r][c] == ALIVE) { 
        naybors++;
//      printf ("N@ r=%d, c=%d.\n", r, c);
      }

  return (naybors);
}


