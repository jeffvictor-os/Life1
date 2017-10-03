// Program to test functions related to neighboring locations,
//  e.g. counting live neighbors.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "lifeglobals.h"


// Args:
// 1: test mapfile name
// 2: row#
// 3: col#
void main (int argc, char *argv[]) {
  int naybors=0, rows=0, cols=0;

  // Sanity test args.
  if (argc < 3) { printf ("Usage: <cmd> mapfile row col\n"); FAIL; }
  rows = atoi(argv[2]);
  cols = atoi(argv[3]);

  // Read in test map
  readmapfile (argv[1], currmap, &rows, &cols);

  // Allocate the other map.
  allocmap (nextmap, DIM);

  // Count naybors of the location specified on the cmd line.
  naybors =  CountNaybors (currmap, rows, cols) ;

  printf ("There are %d neighbors of row %d, col %d.\n", 
          naybors, atoi(argv[2]), atoi(argv[3]));
  p_currmap = currmap;
  p_nextmap = nextmap;

  // Copy one map to the other.
  CopyUniverse(nextmap, currmap);

  // Repeat above, result should be the same: 
  // Count naybors of the location specified on the cmd line.
  naybors =  CountNaybors (currmap, atoi(argv[2]), atoi(argv[3])) ;

  printf ("There are %d neighbors of row %d, col %d.\n", 
          naybors, atoi(argv[2]), atoi(argv[3]));



}

