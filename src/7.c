#include <stdio.h>

#define NTH_PRIME 10001

int isPrime(long long n) {

	if (n < 2) {
		return 0;
	} else if (n == 2) {
		return 1;
	}

	for (long i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

long long getNthPrime(int n) {

	if (n <= 0) {
		return 0;
	} else if (n == 1) {
		return 2;
	} else if (n == 2) {
		return 3;
	}

	int i = 1;
	n -= 2;

	while (n > 0) {

		if (isPrime((6 * i) - 1) && --n == 0) {
			return ((6 * i) - 1);
		}

		if (isPrime((6 * i) + 1) && --n == 0) {
			return ((6 * i) + 1);
		}

		++i;
	}

	return -1;
}

int main(void) {

	printf("%dst Prime Number = %lld\n", NTH_PRIME, getNthPrime(NTH_PRIME));

	return 0;
}
