// READMAPFILE: supporting functions to read a file into a 2-D map, and
// write such a map into a file.
//
// Assumes that the length of all of the lines are the same, and that 
// there are as many rows as there are columns.

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "life.h"
// Pointer to Map
//#define DIM 64
//char *map[DIM];

#define FAIL exit(0);

int readmapfile (char *file, char *mymap[], int *xdim, int *ydim) {

  char *buffer;
  char    *line = NULL;
  int      numoflines=0;
  size_t   len=0;
  ssize_t  read;
  FILE    *fp;

  *xdim = *ydim= 0;

  // Open file. Fail with zero.
  fp = fopen (file, "r");
  if (fp == NULL) { FAIL; }

  // Read lines, test each one.
  // Later, size map based on length of first line and number of lines.
  while ((read = getline (&line, &len, fp)) != -1) {
    // With the first line, we can calculate the map dimensions.
    // Then we can allocate space for the pointers to each string, and the strings.
    if (*xdim==0) {
      *xdim= *ydim= strlen (line) -1;

      // Allocate enough pointers for the "rows" which are implemented 
      // as strings. Also allocate the strings.
//    mymap = malloc (*ydim * sizeof(char *));
      for (int i=0; i < *ydim; i++) {
        if ((mymap[i]= (char *) malloc (*xdim)) == (char *) NULL) { FAIL; }
      }
    }

    // Remove trailing newline.
    line[len-1] = '\0';
//  printf ("Retrieved line %d of length %zu :\n", ++numoflines, read-1);
//  printf ("%s", line);
    for (int i=0; i < *xdim; i++) 
      for (int j=0; j < *ydim; j++) mymap[i][j] = line[j];
  }

  // This assumes that the last line is the same length as the rest.

  if (ferror(fp)) { FAIL; }

  free   (line);
  fclose (fp);

  return (1);

}

// Write the map to a file; useful for replaying multiple generations.
// 
int writemapfile (char *file, char *mymap[], int xdim, int ydim) {
  FILE    *fp;

  // Open file. Fail with zero.
  fp = fopen (file, "w");
  if (fp == NULL) { FAIL; }
  
  for (int i=0; i<xdim; i++) {
    fputs (mymap[i], fp);
    fputs ("\n", fp);
  }
  fclose (fp);
  return (1);
}


// Display the map to the terminal window.
int printmap (char *mymap[], int xdim, int ydim) {
  for (int i=0; i<xdim; i++)  
     puts (mymap[i]);
}

void main(int argc, char *argv[])
{
  int  xdim=0, ydim=0;
 
  // Check command line.
  if (argc != 3) { printf ("Usage: readmapfile <infile> <outfile>\n"); exit (0); }

  // Allocate map. 
//for (int row=0; row<xdim; row++) {
//  map[row] = (char *) malloc((size_t) DIM+1);
//  if (map[row] == NULL) { FAIL; } 
//}

  // Read file.
  if (! readmapfile (argv[1], map, &xdim, &ydim))
    printf ("Failed.\n");
  else
    printf ("Succeeded.\n");

  // Write file.
  writemapfile (argv[2], map, xdim, ydim);

  // Display map.
/*printmap (map, xdim, ydim); */
}



