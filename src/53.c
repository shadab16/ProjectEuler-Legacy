#include <stdio.h>

/* Caps the return value at about 1e7 */
unsigned long combinations(const unsigned int n, const unsigned int r) {

	if (r == 0) return 1;
	if (r == 1) return n;
	if (r == 2) return (n * (n - 1)) / 2;

	double c = 1;
	unsigned int denominator = r;

	/* Falling factorial */
	/* http://en.wikipedia.org/wiki/Combination#Example_of_counting_combinations */

	for (unsigned int falls = 0; falls < r; ++falls) {
		c *= (n - falls);
		while (c > 1e6 && denominator) {
			c /= denominator--;
		}
		if (!denominator && c > 1e6) {
			break;
		}
	}

	while (denominator) {
		c /= denominator--;
	}

	return (unsigned long) c;
}

unsigned int count_excess(const unsigned int offset, const unsigned int limit) {

	unsigned int count = 0;

	for (unsigned int n = offset; n <= limit; ++n) {
		for (unsigned int r = 0, flag = 0; 2 * r <= n; ++r) {
			if (flag || combinations(n, r) > 1e6) {
				count += 2;
				flag = 1;
				if (n - r == r) {
					--count;
				}
			}
		}
	}

	return count;
}

int main(void) {

	const unsigned int offset = 23;
	const unsigned int limit = 100;

	printf("%u\n", count_excess(offset, limit));

	return 0;
}

