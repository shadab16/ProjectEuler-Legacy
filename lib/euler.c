#include <stdlib.h>
#include "euler.h"

char* filter_prime_sieve(const size_t limit) {

	char* const sieve = malloc((limit + 1) * sizeof(char));

	for (size_t i = 0; i <= limit; ++i) {
		sieve[i] = 1;
	}

	sieve[0] = 0;
	sieve[1] = 0;

	for (size_t i = 2; i * i <= limit; ++i) {

		if (!sieve[i]) {
			continue;
		}

		for (size_t j = i; i * j <= limit; ++j) {
			sieve[i * j] = 0;
		}
	}

	return sieve;
}

void clear_prime_sieve(char* sieve) {

	free(sieve);
}

unsigned long* get_prime_list(const char* sieve, const size_t limit, size_t* const count) {

	unsigned int clear = 0;
	if (!sieve) {
		sieve = filter_prime_sieve(limit);
		clear = 1;
	}

	size_t primes = 0;
	for (size_t i = 0; i <= limit; ++i) {
		if (sieve[i]) {
			++primes;
		}
	}

	unsigned long* list = malloc(primes * sizeof(unsigned long));
	for (size_t i = 0, j = 0; i <= limit; ++i) {
		if (sieve[i]) {
			list[j++] = i;
		}
	}

	if (clear) {
		clear_prime_sieve((char*) sieve);
	}

	if (count) {
		*count = primes;
	}

	return list;
}

void clear_prime_list(unsigned long* list) {

	free(list);
}

unsigned long long sort_digits(unsigned long long n) {

	unsigned int digits[10] = {0};

	for (; n; n /= 10) {
		++digits[n % 10];
	}

	for (unsigned int i = 0; i < 10; ++i) {
		while (digits[i]--) {
			n  = (n * 10) + i;
		}
	}

	return n;
}

unsigned long long reverse_digits(unsigned long long n) {

	unsigned long long reverse = 0;

	while (n) {
		reverse = (reverse * 10) + (n  % 10);
		n /= 10;
	}

	return reverse;
}

