#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void filter(int* const sieve, const unsigned long limit) {

	sieve[0] = 0;
	sieve[1] = 0;

	for (unsigned long i = 2; i < limit; ++i) {
		sieve[i] = 1;
	}

	for (unsigned long i = 2; i <= sqrt(limit); ++i) {
		if (sieve[i] == 0) {
			continue;
		}
		for (unsigned long j = 2; j <= (limit / i); ++j) {
			sieve[i * j] = 0;
		}
	}
}

int main(void) {

	/* enough buffer for a 100 long streak */
	const unsigned long limit = 111000;
	int* const sieve = malloc((limit + 1) * sizeof(int));

	filter(sieve, limit);

	int maxstreak = 0, a_ = 0, b_ = 0;

	/* |a| < 1000 */
	for (int a = -999; a <= 999; ++a) {
		/* |b| < 1000 and b is a prime number */
		for (int b = 2; b <= 997; ++b) {
			if (sieve[b] == 0) {
				continue;
			}
			int n = 0;
			while (1) {
				if (n*n + a*n + b < 2 || sieve[n*n + a*n + b] == 0) {
					break;
				}
				++n;
			}
			if (n > maxstreak) {
				maxstreak = n;
				a_ = a;
				b_ = b;
			}
		}
	}

	printf("Streak: %d, a: %d, b: %d, product: %d\n", maxstreak, a_, b_, a_ * b_);

	return 0;
}

