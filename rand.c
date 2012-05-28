#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGRAM    "rand"
#define AUTHOR     "V. Silvansky"
#define MAIL       "<v.silvansky@gmail.com>"
#define YEARS      "2012"
#define VERSION    "1.0"

#define MOD        100000000

void printUsage()
{
	printf(
"Usage: %s [lower, upper]\n"
"  [lower] and [upper] are both floating point values.\n"
"Prints random floating point number between [lower] and [upper]\n"
"If no bounds provided, %s prints a random number in range [0:1).\n"
"Author: %s %s, %s\n"
"Version: %s\n",
		   PROGRAM, PROGRAM, AUTHOR, MAIL, YEARS, VERSION);
}

void seed()
{
	srandomdev();
}

float getValue(float lower, float upper)
{
	return lower + ((random() % MOD) / (float)MOD) * (upper - lower);
}

int main(int argc, char *argv[])
{
	if (argc == 2 || argc > 3)
	{
		printUsage();
		return 0;
	}
	
	float lower, upper, value;
	
	if (argc == 1)
	{
		lower = 0.0f;
		upper = 1.0f;
	}
	else
	{
		if (sscanf(argv[1], "%f", &lower) + sscanf(argv[2], "%f", &upper) < 2)
		{
			printUsage();
			return 1;
		}
	}
	
	if (lower == upper)
		value = lower;
	else
	{
		if (lower > upper)
		{
			value = upper; upper = lower; lower = value;
		}
		seed();
		value = getValue(lower, upper);
	}
	
	printf("%f\n", value);
	
	return 0;
}
