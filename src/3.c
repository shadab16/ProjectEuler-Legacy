#include <stdio.h>
#include <math.h>

int is_prime(unsigned long n) {

	if (n < 2 || n % 2 == 0) {
		return 0;
	}

	for (unsigned long i = 3; i * i < n; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int main(void) {

	const unsigned long long number = 600851475143;
	const unsigned long limit = ceil(sqrt(number));

	for (unsigned long i = limit; i > 2; --i) {
		if (number % i == 0 && is_prime(i)) {
			printf("%ld\n", i);
			break;
		}
	}

	return 0;
}

