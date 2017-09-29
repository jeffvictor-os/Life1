// Program to test readmapfile() and writemapfile().
//
// Assumes that the map is a square.

#include <stdlib.h>
#include <stdio.h>
// Solaris: #include <strings.h>
#include <string.h>

#include "lifeglobals.h"
// Pointer to Map
//#define DIM 64
//char *map[DIM];

#define FAIL printf ("Help!\n"); exit(0);

int readmapfile ();
int writemapfile ();

// Display the map to the terminal window.
int printmap (char *mymap[], int rowdim, int coldim) {
  for (int r=0; r<rowdim; r++)  
     puts (mymap[r]);
}

void main(int argc, char *argv[])
{
  int  rowdim=0, coldim=0;
 
  // Check command line.
  if (argc != 3) { printf ("Usage: readmapfile <infile> <outfile>\n"); exit (0); }

  // Read file.
  if (! readmapfile (argv[1], map, &rowdim, &coldim))
    printf ("Failed.\n");

  // Write file.
  writemapfile (argv[2], map, rowdim, coldim);

  // Display map.
//printmap (map, rowdim, coldim); 
}



