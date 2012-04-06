#include <stdio.h>
#include "euler.h"

int main(void) {

	/*
	 * [1..9] -> 45, [1..8] -> 36, [1..6] -> 21, [1..5] -> 15
	 * ie, the sum of digits of these pandigital ranges is a multiple of 3.
	 * This leaves [1..7] and [1..4] to search for pandigital primes.
	 */

	const size_t limit = 7654321;
	char* sieve = filter_prime_sieve(limit);

	for (size_t i = 7654321; i >= 1234567; --i) {

		if (!sieve[i]) {
			continue;
		}

		unsigned int pandigital = 0;
		for (size_t n = i; n; n /= 10) {
			if (n % 10) {
				pandigital |= 1 << ((n % 10) - 1);
			}
		}

		if (pandigital == 0x7F) {
			printf("%u\n", i);
			break;
		}
	}

	clear_prime_sieve(sieve);

	return 0;
}

