#include <stdio.h>

#include "lifeglobals.h"

void main (int argc, char *argv[]) {

  // Test args.

  // Read map file into currmap for test.
  readmapfile (argv[1], currmap, DIM, DIM) {

  // Copy currmap to nextmap.
  CopyUniverse();

  // Write nextmap to file.
  writemapfile (argv[2], L_OUT, nextmap, DIM, DIM) {

  // Count neighbors of location (1,1)
  printf ("Loc 1,1 has :%d: neighbors.\n", 
          CountNaybors (nextmap, 1, 1));  
  
}


