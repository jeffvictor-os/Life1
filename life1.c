//
// Life1: Conway's Game of Life.
//
// Usage: life1 [-g <gen>]  [-p [-t <time>]] [-n] \
//              [-i infile] [-o outfile] [-l logfile]
//              [-d]
//        Options:
//          -d : debug mode
//          -g <gen>:  Number of generations to run.
//          -t <time>: Duration of each generation, in hundredths of a second.
//                     <time> must be an integer
//          -n  detect a static map ("no" change) and stop, reporting this condition.
//          -s  report statistics, e.g. number of turns, deaths, births, 
//          -i <infile>: an ASCII file of the initial pattern; it 
//          represents each location with a character. A space or '0'
//          means the location is empty. A '1' means it is occupied.
//          -o <outfile>: an ASCII file that represents the pattern after 
//          the number of generations specified by -g.
//          -l <logfile>: an ASCII file that represents the map of each 
//             generation, with a one-line label between generations.
//
// Future:
//   -m  detect map size from input file.
//   -? <X>:<Y>  specify map dimensions on command line.
//
// High level structure:
// 1. Generate initial pattern
// 2. Display the current pattern
// 3. Calculate next generation
// 4. Make the next generation the current generation
// 5. Goto 2

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "lifeglobals.h"

void printusage() {
  printf ("Usage: life1 [-d] [-g <gen>]  [-p [-t <time>]] [-n] [-s] \
 [-i infile] [-o outfile] [-l logfile]\n");
}

// Display the map to the terminal window.
int DisplayMap (char *mymap[], int turn) {
  printf ("Turn %d.\n", turn);
  for (int r=0; r<DIM; r++)
     puts (mymap[r]);
}

void main (int argc, char *argv[]) {
  char c, infile[80], outfile[80], logfile[80];
  int  rows=0, cols=0, turn=0;
  int  num_gens=20, gen_time=450000000;
  int  printGen=0, detect_change=0, changed=0, report_stats=0;
  int  tflag=0, iflag=0, oflag=0, lflag=0;
  struct timespec pauz;
  FILE *fp;

  // Handle command-line arguments.
  while ((c = getopt (argc, argv, "dpg:i:l:no:st:")) != -1)
    switch (c)
    {
      case 'd':
        debug=1;
        break;
      case 'p':
        printGen=1;
        break;
      case 'g':
        num_gens=(atoi(optarg));
        break;
      case 't':
        tflag=1;
        gen_time=10000000*atoi(optarg); // Option is 1/100s of a second.
        break;
      case 'i':
        strncpy (infile, optarg, 64);
        infile[64]='\0';   // For safety.
        iflag = 1;
        break;
      case 'l':
        strncpy (logfile, optarg, 64);
        logfile[64]='\0';   // For safety.
        lflag = 1;
        break;
      case 'n':
        detect_change=1;
        break;
      case 'o':
        strncpy (outfile, optarg, 64);
        outfile[64]='\0';   // For safety.
        oflag = 1;
        break;
      case 's':
        report_stats=1;
        break;
      case '?':
        { printusage(); FAIL; }
        break;
    }

  // Check for incompatible options.
  if (tflag && !printGen) { printusage(); FAIL; }

  // Set the delay between generations.
  pauz.tv_sec =gen_time/1000000000;
  pauz.tv_nsec=gen_time%1000000000;
  
// 1. Generate initial pattern
//    This will allow multiple methods for this:
//    M1. Generate one randomly - useful for filling out the test matrix
//    M2. Manually create a map in an ASCII file. Read the file to generate 
//        the initial pattern.

  p_currmap = currmap;
  p_nextmap = nextmap;

  // Initialize currmap from file, and an empty nextmap.
  readmapfile (infile, p_currmap, &rows, &cols);
  allocmap    (p_nextmap, DIM);

  // For the first time, only, copy current to next.
  CopyUniverse(p_nextmap, p_currmap);

  for (turn=1; turn<=num_gens; turn++) {
    changed=Turn();                         // Compute next generation.
    CopyUniverse(p_currmap, p_nextmap);     // Overwrite curr gen with next.
    if (printGen) DisplayMap (p_currmap, turn);
    if (lflag) { printf ("Logging...\n"); writemapfile (logfile, L_LOG, currmap, DIM, DIM, turn); }
    if (detect_change && !changed) {
      if (printGen) printf ("Turn %d: Map stopped changing.\n", turn);
      break;
    }
    nanosleep (&pauz, NULL);
  }

  if (report_stats) {
    printf ("At turn %d, there had been %d births and %d deaths.\n", births, deaths);
  }

  if (oflag) {
    writemapfile (outfile, L_OUT, currmap, DIM, DIM, turn-1);
    if ((fp = fopen (outfile, "a")) == NULL) { printf ("Couldn't open output file.\n"); FAIL; }
    fprintf (fp, "Turn %d: Map stopped changing.\n", turn);
    fclose (fp);
  }

}
