#include <stdio.h>

int main(void) {

	unsigned long sum = 0;
	const unsigned long powers[10] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};

	for (size_t i = 1000; i < 300000; ++i) {
		unsigned long n = i, accumulate = 0;
		while (n) {
			accumulate += powers[n % 10];
			n /= 10;
		}
		if (accumulate == i) {
			sum += i;
		}
	}

	printf("%lu\n", sum);

	return 0;
}

