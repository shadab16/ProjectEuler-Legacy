#include <stdio.h>

int main(void) {

	const unsigned int target = 99, offset = 21781;
	unsigned long count = 19602, n = offset;

	while (1) {
		unsigned int bouncy = 0;
		unsigned int incr = 0, decr = 0, prev = n % 10;

		for (unsigned long n_ = n; n_; n_ /= 10) {
			const unsigned int digit = n_ % 10;
			if (digit > prev) {
				incr = 1;
			} else if (digit < prev) {
				decr = 1;
			}
			if (incr && decr) {
				bouncy = 1;
				break;
			}
			prev = digit;
		}

		if (bouncy) {
			++count;
			if (count * 100 == target * n) {
				break;
			}
		}

		++n;
	}

	printf("%lu\n", n);

	return 0;
}

