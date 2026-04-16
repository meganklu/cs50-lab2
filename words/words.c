/**
 * words.c
 * Megan Lu
 * COSC050, 26S
 *
 * Description: breaks input into a series of words, one per line.
 *
 * Usage: words [filename]...
 * reads from stdin when no filenames are given.
 * reads from each file in sequence
 * reads from stdin when special file name - is given as one of the filenames
 *
 * Exit: zero if program terminates normally; non-zero if any error
 * (e.g., failure to open a file named as a command-line argument).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
bool processFile(FILE* in);

/* ***************************
 * main
 */
int main(const int argc, const char* argv[])
{
	const char* progName = argv[0];	// name of this program
	const char* stdinName = "-"; // special filename to read stdin
	FILE* current = stdin; // current file (default is stdin)
	
	// No arguments
	if (argc == 1) {
		// Process input from stdin
		if (processFile(current)) {
			exit(0);
		}
	}
	// Loop through filename arguments
	for (int i = 1; i < argc; i++)  {
		if (strcmp(argv[i], stdinName) == 0) {
			// Special character, skip opening file
			current = stdin;
		}
		else if ((current = fopen(argv[i], "r")) == NULL) {
			// Failed to open file
			fprintf(stderr, "%s: cannot open file '%s'\n", progName, argv[i]);
			exit(1);
		}

		// Process the file and confirm success/failure
		bool status = processFile(current);
		
		if (strcmp(argv[i], stdinName) != 0) {
			// Only close files (not stdin)
			fclose(current);
		}
		else {
			// Reset EOF flag of stdin
			// Enables multiple reads of stdin
			clearerr(stdin);
		}

		if (!status) {
			fprintf(stderr, "%s: error processing file '%s'\n", progName, argv[i]);
			exit(2);
		}
	}
	exit(0);
}

/* ***************************
 * processFile
 * Breaks input into a series of words, one per line in stdout.
 *
 * Assumes file 'in' is open for reading.
 * Returns true if input file processed completely and no
 * output errors.
 */
bool processFile(FILE* in)
{
	char c; // character from input
	bool prevChar = false; // true if previous character was a letter
	
	// Loop through the characters of input
	while ((c = fgetc(in)) != EOF) {
		// Determine type of character
		if (isalpha(c) != 0) {
			// Letter printed to stdout
			if (fputc(c, stdout) == EOF) {
				// fputc returns EOF on error
				fprintf(stderr, "output error\n");
				return false;
			}
			prevChar = true;
		}
		else {
			// Non-letter character
			// Only add a new line to end a word
			// (i.e., if previous character was a letter)
			if (prevChar) {
                        	if (fputc('\n', stdout) == EOF) {
                                	// fputc returns EOF on error
                                	fprintf(stderr, "output error\n");
                                	return false;
				}
			}
			prevChar = false;
		}
	}
	return feof(in); // true if reached EOF on input file
}
