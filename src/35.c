#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void filter(int* const sieve, const unsigned long limit) {

	for (unsigned long i = 0; i < limit; ++i) {
		sieve[i] = 1;
	}

	sieve[0] = 0;
	sieve[1] = 0;

	unsigned long limit_ = sqrt(limit);
	for (unsigned long i = 2; i <= limit_; ++i) {

		if (sieve[i] == 0) {
			continue;
		}

		for (unsigned long j = 2; j <= (limit / i); ++j) {
			sieve[i * j] = 0;
		}
	}
}

unsigned int check_circular_prime(int* const sieve, unsigned long prime) {

	unsigned long prime_ = prime;

	unsigned int digits = ceil(log10(prime_));
	unsigned int rotations = digits - 1;
	unsigned int count = digits;

	unsigned int flag = 0; /* flag for not a prime */

	while (rotations--) {

		prime_ = (prime_ / 10) + prime_ % 10 * pow(10, digits - 1);

		if (prime_ == prime) {
			// We've got a duplicate
			--count;
		}

		// One bad apple,...
		if (flag == 1 || sieve[prime_] == 0) {
			if (flag == 0) {
				flag = 1;
				rotations = digits - 1;
			}
			sieve[prime_] = 0;
		}
	}

	if (flag == 1) {
		return 0;
	}

	/* Gotta re mark all the rotations as not prime
	   so they won't be counted multiple times */

	rotations = digits - 1;
	while (rotations--) {
		prime_ = (prime_ / 10) + (prime_ % 10) * pow(10, digits - 1);
		sieve[prime_] = 0;
	}

	return count;
}

int main(void) {

	const unsigned long limit = 10000000;
	int* const sieve = malloc((limit + 1) * sizeof(int));
	unsigned int circular = 0;

	filter(sieve, limit);

	for (unsigned long i = 0; i < limit; ++i) {
		if (sieve[i] == 1) {
			circular += check_circular_prime(sieve, i);
		}
	}

	free(sieve);

	printf("Circular Primes: %u\n", circular);

	return 0;
}

