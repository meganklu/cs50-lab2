/**
 * histo.c
 * Megan Lu
 * COSC050, 26S
 *
 * Description: reads a series of positive integers form stdin
 * and prints out a histogram with 16 bins. 
 *
 * Usage: histo
 * reads from stdin, assumes smallest integer is 0.
 *
 * Exit: always exits with zero status
 * (program has no arguments and does not check input for errors)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void printRange(int binSize);
bool addValue(int bins[], int binSize, int value);
int doubleBinSize(int bins[], int binSize);
void printHisto(int bins[], int binSize);

// Global variables
const int binCount = 16; // fixed number of bins in the histogram

/* ***************************
 * main
 */
int main(const int argc, const char* argv[])
{
	int binSize = 1; // initial default bin size
	int bins[binCount]; // array for histogram bins
	int value; // number read in from stdin
	
	// Each bin initially holds 0 values
	for (int i = 0; i < binCount; i++) {
		bins[i] = 0;
	}
	
	// Print initial range
	printRange(binSize);

	// Read from standard input until stdin is not an int
	while (scanf("%d", &value) > 0) {
		// Value converted and assigned successfully
		// Ignore negative integers
		if (value >= 0) {
			// Loops until added value successfully to histogram
			while (!addValue(bins, binSize, value)) {
				// If not successful, scale bins
				binSize = doubleBinSize(bins, binSize);
			}
		}	
	}

	// Finished reading values, print histogram
	printHisto(bins, binSize);
	exit(0);
}

/* ***************************
 * printRange
 * Prints the current bin size and range to stdin.
 */
void printRange(int binSize) 
{
	printf("%d bins of size %d for range [0,%d)\n", binCount, binSize, (binCount * binSize));
}

/* ***************************
 * addValue
 * Adds the input value to the corresponding bin in the histogram.
 *
 * Assumes the value is an integer >= 0.
 * Returns true if the value was added successfully and
 * false if the value is outside of the histogram range.
 */
bool addValue(int bins[], int binSize, int value)
{
	// Check if the value is within the histogram range
	if (value >= binSize * binCount) {
		return false;
	}

	// Calculate the corresponding bin index
	// Integer division (value and binSize are int)
	// Result is truncated toward 0 (floor)
	int binIndex = (value / binSize);
	// Increase the count of values in the bin
	bins[binIndex]++;

//	printf("adding %d to bin at index %d, count is now %d\n", value, binIndex, bins[binIndex]);

	return true;
}

/* ***************************
 * doubleBinSize
 * Doubles bin size and redistributes count of bins
 * then prints updated bin size and range.
 * 
 * Returns the updated bin size.
 */
int doubleBinSize(int bins[], int binSize) 
{
	// Combines bins as pairs to fill first half of histogram
	for (int i = 0; i < binCount / 2; i++) {
		bins[i] = bins[i * 2] + bins[(i * 2) + 1];
	}

	// Set second half of histogram bins to zero
	for (int i = binCount / 2; i < binCount; i++) {
		bins[i] = 0;
	}
	
	int newBinSize = binSize * 2;
	printRange(newBinSize);
	return newBinSize;
}

/* ***************************
 * printHisto
 * Prints the histogram to stdin with [low:high] range indicators
 * for each row and stars to represent the count of values
 * in the bin. 
 */
void printHisto(int bins[], int binSize)
{
	// Calculate largest number in the range for spacing
	int max = (binCount * binSize) - 1;
	// Determine spacing from the number of digits in max
	int spacing = 0;
	while (max != 0) {
		max /= 10;
		spacing++;
	}	

	for (int i = 0; i < binCount; i++) {
//		printf("bin %d has count %d\n", i, bins[i]);

		// Calculate the bin range
		int min = i * binSize;
		int max = min + binSize - 1;

		// Print the range of the bin
		printf("[%*d:%-*d] ", spacing, min, spacing, max);

		// Print a star for every count in the bin
		for (int c = 0; c < bins[i]; c++) {
			printf("*");
		}

		// Finish line with a return
		printf("\n");
	}
}
