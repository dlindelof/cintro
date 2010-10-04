#include <stdio.h>

/*
    print Celsius-Fahrenheittable
    for celsius = 0, 20, ..., 300 
*/

#define LOWER   0    /* lower limit of temperature scale */
#define UPPER 300    /* upper limit */
#define STEP   20    /* step size */

int c2f(int celsius);

main()
{
	int fahr, celsius;

	celsius = LOWER;
	while (celsius <= UPPER) {
		fahr = c2f(celsius);
		printf("%d\t%d\n", celsius, fahr);
		celsius = celsius + STEP;
	}
}

int c2f(int celsius)
{
	return 9 * celsius / 5 + 32;
}
