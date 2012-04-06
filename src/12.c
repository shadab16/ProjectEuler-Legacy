#include <stdio.h>
#include <math.h>

int divisor_count(long n) {
	int count = 0;
	for (long i = 1; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			count++;
		}
	}
	return 2 * count;
}

int main(void) {

	long num = 0;
	long idx = 1;

	while (1) {
		num += idx++;

		if (num < 10000000) {
			continue;
		}

		int count = divisor_count(num);
		if (count > 500) {
			printf("Count: %d\n", count);
			break;
		}
	}

	printf("Number: %ld\n", num);

	return 0;
}

