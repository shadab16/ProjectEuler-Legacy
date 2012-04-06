#include <stdio.h>
#include "euler.h"

unsigned int count_cycle(unsigned int d) {

	int digits[2000] = {0};
	int* digit = digits;
	int* cycle = digits;

	int count = 0, n = 10;

	while (digit - digits < 2000) {

		*digit = n / d;
		n = (n % d) * 10;

		if (*digit == *cycle && digit != cycle) {
			if (digit - cycle == count) {
				break;
			}
			++cycle;
			++count;
		} else {
			cycle = digits;
			count = 0;
		}

		++digit;
	}

	return count;
}

int main(void) {

	size_t limit = 1000;
	int* const sieve = filter_primes(0, limit);

	unsigned int maxd = 0, maxcycle = 0;

	for (size_t d = 10; d < limit; ++d) {
		if (!sieve[d]) {
			continue;
		}
		unsigned int cycle = count_cycle(d);
		if (cycle > maxcycle) {
			maxcycle = cycle;
			maxd = d;
		}
	}

	printf("d: %u, cycle: %u\n", maxd, maxcycle);

	return 0;
}

/*
	1/7

	7 | 10 | 1
	   - 7
	7 | 30 | 4
	   -28
	7 | 20 | 2
	   -14
	...
*/
