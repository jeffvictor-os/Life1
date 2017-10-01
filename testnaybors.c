// Program to test functions related to neighboring locations,
//  e.g. counting live neighbors.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "lifeglobals.h"
#include "life.h"


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
  readmapfile (argv[1], map1, &rows, &cols);

  // Allocate the other map.
  allocmap (map2, DIM);

  // Count naybors of the location specified on the cmd line.
  naybors =  CountNaybors (map1, rows, cols) ;

  printf ("There are %d neighbors of row %d, col %d.\n", 
          naybors, atoi(argv[2]), atoi(argv[3]));
  currmap = map1;
  nextmap = map2;

  // Copy one map to the other.
  CopyUniverse();

  SwitchMaps();

  // Repeat above, result should be the same: 
  // Count naybors of the location specified on the cmd line.
  naybors =  CountNaybors (map1, atoi(argv[2]), atoi(argv[3])) ;

  printf ("There are %d neighbors of row %d, col %d.\n", 
          naybors, atoi(argv[2]), atoi(argv[3]));



}

