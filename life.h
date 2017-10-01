// Include file with global declarations.
#define ALIVE '*'
#define DEAD  ' '

#define FAIL printf ("Help!\n"); exit(0);

char **currmap, **nextmap;



int readmapfile (char *file, char *mymap[], int *rowdim, int *coldim);
int writemapfile (char *file, char *mymap[], int rowdim, int coldim) ;
char **allocmap(char **mymap, int dimension);
int SwitchMaps() ;
int CopyUniverse() ;
int CountNaybors (char *mymap[], int row, int col) ;
int printmap (char *mymap[], int xdim, int ydim) ;



