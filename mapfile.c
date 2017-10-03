// MAPFILE: supporting functions to read a file into a 2-D map, and
// write such a map into a file.
//
// Assumes that the length of all of the lines are the same, and that 
// there are as many rows as there are columns.

#include <stdlib.h>
#include <stdio.h>
// Solaris: #include <strings.h>
#include <string.h>

#include "life.h"
// In-memory map
// #define DIM 8
// char *map[DIM];

// Allocate the DIM quantity of strings that will be used as the map.
// The calling program can use *either* allocmap() *or* readmapfile()
// to create the map.
char **allocmap(char **mymap, int dimension) {
  int r=0;

  for (r=0; r<dimension; r++)
    if ((mymap[r]= (char *)malloc (dimension)) == (char *) NULL) { FAIL; }
}

int readmapfile (char *file, char *mymap[], int *rowdim, int *coldim) {

  char *buffer;
  char    *line = NULL;
  int      c=0, r=0, numoflines=0;
  size_t   len=0;
  ssize_t  read;
  FILE    *fp;

  // "c" is columns. "r" is rows.
  *coldim = *rowdim= 0;

  // Open file. Fail with zero.
  fp = fopen (file, "r");
  if (fp == NULL) { FAIL; }

  // Read lines, test each one.
  // Later, size map based on length of first line and number of lines.
  while ((read = getline (&line, &len, fp)) != -1) {
    // Determine (square) map dimensions from first line.
    if   (*rowdim==0) *coldim= *rowdim= strlen(line)-1;

    //   Check import format for subsequent lines.
    else if (strlen(line) != *rowdim+1) { FAIL; }
  
    // Remove trailing newline, allocate string, copy.
    line[*coldim] = '\0';
    if ((mymap[r]= (char *) malloc (*coldim)) == (char *) NULL) { FAIL; }
    strncpy (mymap[r], line, DIM);

    r++;    // Do next row.
  }

  if (ferror(fp)) { FAIL; }
  free   (line);
  fclose (fp);

  return (1);

}

// Write the map to a file; useful for replaying multiple generations.
// 
int writemapfile (char *file, int mode, char *mymap[], int rowdim, int coldim, int turn) {
  int   r=0;
  FILE *fp;

  // Open file. Fail with zero.
  if (mode==L_LOG) fp = fopen (file, "a");
  else             fp = fopen (file, "w");
  if (fp == NULL) { FAIL; }
 
  fprintf (fp, "Turn: %d\n", turn); 
  for (r=0; r<rowdim; r++) {
    fprintf (fp, "%s\n", mymap[r]);
  }
  fclose (fp);
  return (1);
}





