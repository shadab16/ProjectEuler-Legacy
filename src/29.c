#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int sort_mpz_t(const void* a, const void* b) {

	return mpz_cmp(*(mpz_t*) a, *(mpz_t*) b);
}

int main(void) {

	const size_t limit = 100;
	const size_t elements = (limit - 1) * (limit - 1);

	mpz_t* num = malloc(elements * sizeof(mpz_t));

	for (size_t a = 2; a <= limit; ++a) {
		for (size_t b = 2; b <= limit; ++b) {

			const size_t idx = ((a - 2) * (limit - 1)) + (b - 2);

			mpz_init(num[idx]);
			mpz_ui_pow_ui(num[idx], a, b);
		}
	}

	qsort(num, elements, sizeof(*num), sort_mpz_t);

	size_t count = 1;
	for (size_t i = 1; i < elements; ++i) {
		if (mpz_cmp(num[i], num[i - 1]) == 0) {
			continue;
		}
		count++;
	}

	printf("%d\n", count);

	for (size_t i = 0; i < elements; ++i) {
		mpz_clear(num[i]);
	}
	free(num);

	return 0;
}

