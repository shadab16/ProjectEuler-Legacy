#include <stdio.h>

int main(void) {

	const unsigned long width = 1001;
	unsigned long sum = 1, n = 1;

	for (unsigned long increment = 2; increment < width; increment += 2) {

		/* move to the first term of AP */
		n += increment;

		/* add the sum of first 4 terms */
		sum += (4 * n) + (6 * increment);

		/* set n to the last term of AP */
		n += 3 * increment;
	}

	printf("%lu\n", sum);

	return 0;
}

