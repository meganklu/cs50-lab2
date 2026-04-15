/**
 * chill.c
 * Megan Lu
 * COSC050, 26S
 *
 * Description: calculates wind chill based on the current temperature and 
 * wind speed.
 * 
 * Usage:
 * chill
 * chill temperature
 * chill temperature velocity
 *
 * where temperature is expressed as a floating-point number in degrees F 
 * and velocity is a floating-point number in miles per hour. 
 *
 * Exit: zero if program terminates normally; non-zero if wrong number of
 * arguments or arguments are out of range.
 */

#include <stdio.h>
#include <math.h>

/* ***************************
 * comment
 */
int main(int argc, char *argv[])
