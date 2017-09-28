//
// Life1: Conway's Game of Life.
//
// Usage: life1 -g # [-l logfile] mapfile outfile
//        mapfile is an ASCII file that of the initial pattern; it 
//          represents each location with a character. A space or '0'
//          means the location is empty. A '1' means it is occupied.
//        outfile is an ASCII file that represenets the pattern after 
//          the number of generations specified by -g.
//        logfile is optional. A map of each generation will be written 
//          logfile, with a one-line separator between generations.
// High level structure:
// 1. Generate initial pattern
// 2. Display the current pattern
// 3. Calculate next generation
// 4. Make the next generation the current generation
// 5. Goto 2

#include "life.h"

void main (int argc, char *argv[]) {

// Handle command-line arguments.


// 1. Generate initial pattern
// We allow multiple methods for this:
// M1. Generate one randomly - useful for filling out the test matrix
// M2. Represent a map in an ASCII file. Read the file to generate the 
//     initial pattern.






}

