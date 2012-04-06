#include <stdio.h>

int main(void) {

	unsigned long long prime = 2;

	for (unsigned long i = 0; i < 7830456/8; ++i) {
		prime = (prime << 8) % 10000000000;
	}

	prime = 1 + (prime * 28433) % 10000000000;

	printf("Last 10 digits: %llu\n", prime);

	return 0;
}

