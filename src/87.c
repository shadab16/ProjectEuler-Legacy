#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "euler.h"

int main(void) {

	const size_t limit = 5e7;
	const size_t primelimit = sqrt(limit - 24);

	size_t primes = 0;
	unsigned long* const primelist = get_primes(primelimit, &primes);
	char* const sieve = calloc(limit * sizeof(char), sizeof(char));

	for (unsigned long* p1 = primelist; p1 < primelist + primes; ++p1) {

		unsigned long n1 = *p1 * *p1;
		for (unsigned long* p2 = primelist; p2 < primelist + primes; ++p2) {

			unsigned long n2 = *p2 * *p2 * *p2;
			if (n1 + n2 + 16 >= limit) {
				break;
			}
			for (unsigned long* p3 = primelist; p3 < primelist + primes; ++p3) {

				unsigned long n3 = *p3 * *p3; n3 *= n3;
				if (n1 + n2 + n3 >= limit) {
					break;
				}
				sieve[n1 + n2 + n3] = 1;
			}
		}
	}

	size_t count = 0;
	for (size_t i = 0; i < limit; ++i) {
		if (sieve[i]) {
			++count;
		}
	}
	printf("%zu\n", count);

	free(sieve);
	clear_primes(primelist);

	return 0;
}

