#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void filter(int* const sieve, const size_t limit) {

	for (size_t i = 0; i < limit; ++i) {
		sieve[i] = 1;
	}

	sieve[0] = 0;
	sieve[1] = 0;

	for (size_t i = 2; i <= sqrt(limit); ++i) {

		if (sieve[i] == 0) {
			continue;
		}

		for (size_t j = 2; j <= (limit / i); ++j) {
			sieve[i * j] = 0;
		}
	}
}

int main(void) {

	const size_t limit = 1000000;
	int* const sieve   = malloc((limit + 1) * sizeof(int));
	unsigned long sum  = 0;

	filter(sieve, limit);

	for (size_t i = 11; i < limit; ++i) {
		if (sieve[i] == 1) {

			size_t n = i;

			/* Truncating from right */
			while (n /= 10) {
				if (sieve[n] == 0) {
					goto next_prime;
				}
			}

			/* Truncating from left */
			size_t mod = 10;
			n = i;
			while (n % mod != n) {
				if (sieve[n % mod] == 0) {
					goto next_prime;
				}
				mod *= 10;
			}

			/* Both truncatable */
			//printf(":: %u\n", i);
			sum += i;
		}
		next_prime:;
	}

	printf("%lu\n", sum);
	free(sieve);

	return 0;
}

