#include <stdio.h>

#include "life.h"
#include "lifeglobals.h"

void main (int argc, char *argv[]) {
  char *currmap[]

  currmap=map1;

// Test args.

// Read map file into currmap for test.
  readmapfile (argv[1], currmap, DIM, DIM) {

// Copy currmap to nextmap.
  CopyUniverse();

// Write nextmap to file.
  writemapfile (argv[2], nextmap, DIM, DIM) {

// Count neighbors of location (1,1)
  printf ("Loc 1,1 has :%d: neighbors.\n", 
          CountNaybors (nextmap, 1, 1));  
  
}


