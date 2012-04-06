#include <stdio.h>
#include "euler.h"

int main(void) {

	const size_t limit = 1e6;
	size_t count = 0;

	char* const sieve = filter_prime_sieve(limit);
	unsigned long* primes = get_prime_list(sieve, limit, &count);

	unsigned long maxprime = 0, maxstreak = 0;

	for (size_t i = 0; i < count; ++i) {

		unsigned long sum = 0, streak = 0;

		for (size_t j = i; j < count && sum + primes[j] < limit; ++j) {
			sum += primes[j];
			++streak;
			if (sieve[sum] && streak > maxstreak) {
				maxstreak = streak;
				maxprime = sum;
			}
		}
	}

	clear_prime_sieve(sieve);
	clear_prime_list(primes);

	printf("Streak: %lu, Prime: %lu\n", maxstreak, maxprime);

	return 0;
}

