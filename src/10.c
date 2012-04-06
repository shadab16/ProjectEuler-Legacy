#include <stdio.h>
#include "euler.h"

int main(void) {

	const unsigned long limit = 2000000;
	unsigned long long sum = 0;

	int* sieve = filter_primes(0, limit);

	for (unsigned long i = 0; i < limit; ++i) {
		if (sieve[i]) {
			sum += i;
		}
	}

	printf("%llu\n", sum);

	clear_sieve(sieve);

	return 0;
}

