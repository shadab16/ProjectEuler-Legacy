#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "euler.h"

typedef struct prime_node {
	unsigned int number;
	unsigned int sorted;
} PRIME;

int sort_prime_nodes(const void* a1, const void* a2) {

	return ((PRIME*) a1)->sorted - ((PRIME*) a2)->sorted;
}

int main(void) {

	const size_t offset = 1000, limit = 9999;
	size_t count = 0;

	int* const sieve = filter_primes(0, limit);

	PRIME prime[1800];

	for (size_t p = offset; p <= limit; ++p) {
		if (sieve[p]) {
			prime[count].number = p;
			prime[count].sorted = sort_digits(p);
			++count;
		}
	}

	clear_sieve(sieve);

	qsort(prime, count, sizeof(PRIME), sort_prime_nodes);

	/*size_t i = 0;
	while (i < count - 1) {
		unsigned int delta[][] = {{0}};
		while (i < count - 1 && prime[i].sorted == prime[i + 1].sorted) {
			delta[di++] = prime[i + 1].number - prime[i].number;
			++i;
		}
	}*/

	return 0;
}

