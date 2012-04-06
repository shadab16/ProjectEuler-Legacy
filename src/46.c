#include <stdio.h>
#include <stdlib.h>
#include "euler.h"

int main(void) {

	const size_t limit = 1e4;
	int* const prime_sieve = filter_primes(0, limit);
	int* const goldbach_sieve = calloc(limit * sizeof(int), sizeof(int));

	for (size_t p = 2; p < limit; ++p) {
		if (!prime_sieve[p]) {
			continue;
		}
		for (size_t x = 1; p + 2*x*x < limit; ++x) {
			goldbach_sieve[p + 2*x*x] = 1;
		}
	}

	for (size_t i = 35; i < limit; i += 2) {
		if (!prime_sieve[i] && !goldbach_sieve[i]) {
			printf("Odd Composite: %u\n", i);
			break;
		}
	}

	free(goldbach_sieve);
	clear_sieve(prime_sieve);

	return 0;
}

