#include <stdio.h>
#include <math.h>

int is_abundant(const unsigned int n) {

	if (n < 12) {
		/* 12 is the smallest abundant number */
		return 0;
	}

	if (n % 6 == 0) {
		/* all multiples of 6 are abundant */
		return 1;
	}

	unsigned int sum = 1, i = 1;

	for (; i < sqrt(n); ++i) {
		if (n % i == 0 && i != 1) {
			sum += i + (n / i);
		}
	}
	if (i * i == n) {
		sum += i;
	}

	return (sum > n);
}

/* Reference: http://mathworld.wolfram.com/AbundantNumber.html */
/* Instead of 28123, we check upto 20161 */

int main(void) {

	int sieve[20162] = {0};
	for (int i = 12; i <= 20161; ++i) {
		sieve[i] = is_abundant(i);
	}

	long sum = 0;
	for (int i = 1; i <= 20161; ++i) {
		int flag = 0;
		for (int j = 12; j <= i - 12 && j <= i / 2; ++j) {
			if (sieve[j] && sieve[i - j]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			sum += i;
		}		
	}

	printf("%ld\n", sum);

	return 0;
}

