#include <stdio.h>

int main(void) {

	const unsigned long long modulus = 1e10;
	unsigned long long accumulate = 0;

	for (unsigned int i = 1; i <= 1000; ++i) {

		unsigned long long result = 1;
		for (unsigned int e = 1; e <= i; ++e) {
			result = (result * i) % modulus;
		}
		accumulate = (accumulate + result) % modulus;
	}

	printf("%llu\n", accumulate);

	return 0;
}

