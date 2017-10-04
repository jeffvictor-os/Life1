// Include file with global declarations.
#define DIM 32

#define ALIVE '*'
#define EMPTY ' '

// Flag for writing the map to a logfile (one map per generation) or just the last gen.
#define L_LOG 0
#define L_OUT 1

#define FAIL printf ("Help!\n"); exit(0);

//char **currmap, **nextmap;
char **p_currmap, **p_nextmap;



int  readmapfile (char *file, char *mymap[], int *rowdim, int *coldim);
int  writemapfile (char *file, int mode, char *mymap[], int rowdim, int coldim, int turn);
char **allocmap(char **mymap, int dimension);
void CopyUniverse(char **dest, char **src) ;
int  CountNaybors (char *mymap[], int row, int col) ;
int  printmap (char *mymap[], int xdim, int ydim) ;
int  Turn();


