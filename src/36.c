#include <stdio.h>

int main(void) {

	unsigned long sum = 0;

	for (unsigned long num = 1; num < 1e6; num += 2) {

		/* 1e6 requires a storage of 20 digits */
		unsigned long long reverse = 0, binary = 0;

		/* Base 10 reversal */
		for (unsigned long n = num; n; n /= 10) {
			reverse = (reverse * 10) + (n % 10);
		}

		if (reverse != num) continue;
		reverse = 0;

		/* Base 2 & its reversal */
		for (unsigned long long n = num, multiplier = 1; n; n >>= 1, multiplier *= 10) {
			binary += multiplier * (n & 1);
			reverse = (reverse * 10) + (n & 1);
		}

		if (reverse != binary) continue;

		//printf(":: %lu, %llu\n", num, binary);
		sum += num;
	}

	printf("%lu\n", sum);

	return 0;
}

