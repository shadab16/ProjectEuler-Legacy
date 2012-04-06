#include <stdio.h>
#include <math.h>

int main(void) {

	unsigned int min_m = 0, min_n = 0, min_delta = 1000;
	unsigned long target = 2000000;

	for (unsigned int m = 1; m <= 2000; ++m) {

		unsigned int n = 1;
		unsigned long product = 0;

		while (product < target) {

			product = ((m * m + m) * (n * n + n)) / 4;
			const unsigned int delta = fabs((double) target - product);
			if (delta < min_delta) {
				min_delta = delta;
				min_m = m;
				min_n = n;
			}
			++n;
		}
	}

	printf("m: %-4u n: %-4u area: %u\n", min_m, min_n, min_m * min_n);

	return 0;
}

