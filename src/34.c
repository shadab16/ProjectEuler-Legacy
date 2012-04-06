#include <stdio.h>

int main(void) {

	unsigned long sum = 0;
	const unsigned long factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

	for (size_t i = 11; i < 3000000; ++i) {
		unsigned long n = i, accumulate = 0;
		while (n) {
			accumulate += factorial[n % 10];
			n /= 10;
		}
		if (accumulate == i) {
			sum += i;
		}
	}

	printf("%lu\n", sum);

	return 0;
}

