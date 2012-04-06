#include <stdio.h>

int main(void) {

	const size_t limit = 1e7;

	unsigned int map[568] = {0};
	unsigned int chain[568] = {0};

	const unsigned int square[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

	/* generate the mapping */
	for (size_t i = 0; i < 568; ++i) {
		unsigned int n = i, sum = 0;
		while (n) {
			sum += square[n % 10];
			n /= 10;
		}
		map[i] = sum;
	}

	/* identify loop terminators */
	for (size_t i = 1; i < 568; ++i) {
		unsigned int n = i;
		while (n != 1 && n != 89) {
			n = map[n];
		}
		chain[i] = n;
	}

	/* count chains terminating with 89 */
	size_t count = 0;
	for (size_t i = 0; i < limit; ++i) {
		unsigned int n = i, sum = 0;
		while (n) {
			sum += square[n % 10];
			n /= 10;
		}
		if (chain[sum] == 89) {
			++count;
		}
	}

	printf("%u\n", count);

	return 0;
}

