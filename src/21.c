#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long sum_divisors(const unsigned long n) {

	unsigned long sum = 0;
	for (unsigned long i = 1; i <= ceil(n/2); ++i) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum;
}

unsigned long sum_amicable(int *const spool, const unsigned long limit) {

	unsigned long sum = 0;

	for (unsigned long i = 1; i < limit; ++i) {
		if (spool[i]) {
			continue;
		}

		unsigned long pair_ = sum_divisors(i);
		if (i == sum_divisors(pair_) && pair_ < limit) {
			if (pair_ != i) {
				sum += i + pair_;
			}
			spool[pair_] = 1;
		}
	}
	return sum;
}

int main(void) {

	const unsigned long limit = 10000;
	int *const spool = calloc(limit * sizeof(int), sizeof(int));

	printf("Sum: %lu\n", sum_amicable(spool, limit));

	return 0;
}

