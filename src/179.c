#include <stdio.h>
#include <stdlib.h>

void filter(int* const sieve, const size_t limit) {
	for (size_t i = 0; i < limit; ++i) {
		sieve[i] = 1;
	}
	sieve[0] = 0;
	sieve[1] = 0;
	for (size_t i = 2; i * i <= limit; ++i) {
		if (sieve[i] == 0) {
			continue;
		}
		for (size_t j = i; i * j <= limit; ++j) {
			sieve[i * j] = 0;
		}
	}
}

inline unsigned int divisor_count(const int* const sieve, const unsigned long n) {
	if (sieve[n]) {
		return 2;
	}
	unsigned int count = 1;
	unsigned long i = 2;
	if (n % 2 == 0) {
		for (; i * i < n; ++i) {
			if (n % i == 0) {
				++count;
			}
		}
	} else {
		for (i = 3; i * i < n; i += 2) {
			if (n % i == 0) {
				++count;
			}
		}
	}
	count <<= 1;
	if (i * i == n) {
		++count;
	}
	return count;
}

int main(void) {

	const size_t limit = 1e7;

	int* const sieve = malloc((limit + 1) * sizeof(int));
	filter(sieve, limit);

	unsigned long count = 0;
	unsigned int d0 = divisor_count(sieve, 2), d1 = 0;

	for (unsigned long i = 2; i < limit; ++i, d0 = d1) {
		d1 = divisor_count(sieve, i + 1);
		if (d0 == d1) {
			/*printf(":: %2lu %2lu -> %u\n", i, i + 1, d0);*/
			++count;
		}
	}

	printf("%lu\n", count);

	return 0;
}

