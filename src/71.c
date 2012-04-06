#include <stdio.h>

typedef struct fraction {
	unsigned long n;
	unsigned long d;
} fraction;

/* get the fraction closest to 3/7 */
fraction closest(unsigned long d) {
	if (d % 7 == 0) --d;
	unsigned long n = (3 * d) / 7;
	return (fraction) {n, d};
}

int main(void) {

	size_t limit = 1e6;
	fraction max = {0, 1};

	for (size_t i = 2; i <= limit; ++i) {
		fraction f = closest(i);
		if (f.n * max.d > f.d * max.n) {
			max = f;
		}
	}

	printf("n/d -> %lu/%lu\n", max.n, max.d);

	return 0;
}

