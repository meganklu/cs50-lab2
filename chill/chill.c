/**
 * chill.c
 * Megan Lu
 * COSC050, 26S
 *
 * Description: calculates wind chill based on the current temperature and 
 * wind speed.
 * 
 * Usage: chill [temperature [velocity]]
 * where temperature is expressed as a floating-point number in degrees F 
 * and velocity is a floating-point number in miles per hour. 
 *
 * Assumes arguments are valid floating-point numbers.
 *
 * Exit: zero if program terminates normally; non-zero if wrong number of
 * arguments or arguments are out of range.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void buildTable(float stepTemp, float stepVel, float startTemp, float endTemp, float startVel, float endVel);
float calculateChill(float temp, float vel);

/* ***************************
 * main
 */
int main(int argc, char *argv[])
{
	const char* progName = argv[0];	// name of this program
	const float minTemp = -99.0; // minimum allowed temperature input
	const float maxTemp = 50.0; // maximum allowed temperature input
	const float minVel = 0.5; // minimum allowed velocity input
	const float stepTemp = 10.0; // default temperature step amount
	const float stepVel = 5.0; // default velocity step amount
	float startTemp = -10.0; // default start temperature
	float endTemp = 40.0; // default end temperature
	float startVel = 5.0; // default start velocity
	float endVel = 15.0; // default end velocity

	// Parse arguments
	if (argc > 3) {
		// More than two arguments
		fprintf(stderr, "usage: %s [temperature [velocity]] where temperature and velocity are floating-point numbers\n", progName);
		exit(1);
	}
	else if (argc > 1) {
		// At least one argument
		// Change from default start and end temperatue
		sscanf(argv[1], "%f", &startTemp);
		endTemp = startTemp;
		// Validate input temperature
		if (startTemp < minTemp) {
			// Input temperature is less than -99
			fprintf(stderr, "%s: Temperature must be greater than or equal to %.1f degrees Fahrenheit\n", progName, minTemp);
			exit(2);
		}
		else if (startTemp > maxTemp) {
			// Input temperature is greater than 50
			fprintf(stderr, "%s: Temperature must be less than or equal to %.1f degrees Fahrenheit\n", progName, maxTemp);
			exit(3);
		}
		
		// Two arguments
		// Change from default start and end velocity
		if (argc == 3) {
			sscanf(argv[2], "%f", &startVel);
			endVel = startVel;
			// Validate input velocity
			if (startVel < minVel) {
				// Input velocity is less than 0.5
				fprintf(stderr, "%s: Wind velocity must be grater than or equal to %.1f MPH\n", progName, minVel);
				exit(4);
			}
		}
	}

	// Build table
	buildTable(stepTemp, stepVel, startTemp, endTemp, startVel, endVel); 
	exit(0);
}

/* ***************************
 * buildTable
 * Print a table of wind chill values for the given temperature range 
 * and velocity range, increasing by the provided step amounts.
 *
 * Assumes valid start, end, and step values.
 */
void buildTable(float stepTemp, float stepVel, float startTemp, float endTemp, float startVel, float endVel)
{
	// Print table header (width of 6 for each column, right-aligned)
	printf("%6s %6s %6s", "Temp", "Wind", "Chill");
	printf("\n%6s %6s %6s", "-----", "-----", "-----");

	// Create a table from the starting temperature to ending temperature
	for (float temp = startTemp; temp <= endTemp; temp += stepTemp) {
		// Add line to separate from the header/different temperatures
		printf("\n");
		// Create a section from the starting velocity to ending velocity
		for (float vel = startVel; vel <= endVel; vel += stepVel) {
			// Calculate wind chill for each temperature and velocity
			float chill = calculateChill(temp, vel);
			// Print formatted row
			// (width of 6 for each column, right-aligned, one decimal)
			printf("%6.1f %6.1f %6.1f\n", temp, vel, chill);
		}
	}	
}

/* ***************************
 * calculateChill
 * Returns the wind chill for given temperature and velocity values
 * using the equation:
 * Wind Chill = 35.74 + 0.6215T - 35.75(V^0.16) + 0.4275T(V^0.16)
 *
 * Assumes valid temperature and velocity values.
 */
float calculateChill(float temp, float vel)
{
	return (35.74 + (0.6215 * temp) - (35.75 * powf(vel, 0.16)) + (0.4275 * temp * pow(vel, 0.16)));
}
