#include <stdio.h>
#include <stdlib.h>

unsigned long long count_ways(unsigned long long* const cache, const unsigned int digits, const unsigned int d1, const unsigned int d2) {

	if (digits == 0) {
		return 1;
	}
	if (digits == 1) {
		return 10 - d1 - d2;
	}

	const size_t idx = (100 * (digits - 1)) + (10 * d2) + d1;
	if (cache[idx]) {
		return cache[idx];
	}

	unsigned long long count = 0;
	for (unsigned int i = 0; i < 10 - d1 - d2; ++i) {
		count += count_ways(cache, digits - 1, d2, i);
	}

	return cache[idx] = count;
}

int main(void) {

	const unsigned int digits = 20;
	unsigned long long* cache = calloc(digits * 10 * 10 * sizeof(unsigned long long), sizeof(unsigned long long));

	/* number of ways, including the leading 0 */
	unsigned long long count = count_ways(cache, digits, 0, 0);

	/* minus the number of ways when we have a leading 0 */
	count -= count_ways(cache, digits - 1, 0, 0);

	printf("%llu\n", count);

	free(cache);

	return 0;
}
