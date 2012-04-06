#include <stdio.h>
#include <stdlib.h>

int main(void) {

	const size_t limit = 1e7;

	unsigned int* const sieve = malloc(limit * sizeof(unsigned int));

	/* Filter the divisor counts */
	for (size_t i = 2; i * i < limit; ++i) {
		for (size_t j = i; i * j < limit; ++j) {
			sieve[i * j] += (i == j) ? 1 : 2;
		}
	}

	unsigned long count = 0;

	/* Count the solutions */
	for (size_t i = 2; i < limit - 1; ++i) {
		if (sieve[i] == sieve[i + 1]) {
			++count;
		}
	}

	printf("%lu\n", count);

	return 0;
}

