#include <stdio.h>
#include "euler.h"

int main(void) {

	size_t limit = 1e9;
	size_t count = 0;

	for (size_t i = 0; i < limit; ++i) {
		if (i % 10 == 0) {
			continue;
		}

		unsigned long sum = i + num_reverse(i);
		unsigned long flag = 0;

		while (sum) {
			flag |= 1 << (sum % 10);
			sum /= 10;
		}

		if (!(flag & 0x155)) {
			++count;
		}
	}

	printf("%u\n", count);

	return 0;
}

