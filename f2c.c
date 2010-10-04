#include <stdio.h>

/*
    print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 
*/

#define LOWER   0    /* lower limit of temperature scale */
#define UPPER 300    /* upper limit */
#define STEP   20    /* step size */

int f2c(int fahr);

main()
{
	int fahr, celsius;

	fahr = LOWER;
	while (fahr <= UPPER) {
		celsius = f2c(fahr);
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + STEP;
	}
}

int f2c(int fahr)
{
	return 5 * (fahr-32) / 9;
}
