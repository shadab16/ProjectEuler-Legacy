#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(void) {

	const unsigned long offset = 50000, limit = 1000000;

	mpz_t fib0, fib;
	mpz_init(fib);
	mpz_init(fib0);

	mpz_fib2_ui(fib, fib0, offset - 1);

	/* F(n), for n = 1000000, has 208988 digits */

	char* numstr = calloc(210000 * sizeof(char), sizeof(char));
	char* numstr_end = numstr;

	for (unsigned long i = offset; i <= limit; ++i) {

		if (i % 5000 == 0) {
			printf("Crossed... %lu\n", i);
		}

		mpz_add(fib0, fib0, fib);
		mpz_swap(fib0, fib);

		mpz_get_str(numstr, 10, fib);

		unsigned int pandigital = 0;

		for (int x = 0; x <= 8; ++x) {
			if (*(numstr + x) - '0') {
				pandigital |= 1 << (*(numstr + x) - '1');
			}
		}

		if (pandigital != 0x1FF) {
			continue;
		}
		printf("First 9 pandigital :: %lu\n", i);

		while (*numstr_end) ++numstr_end;
		pandigital = 0;

		for (int x = 1; x <= 9; ++x) {
			if (*(numstr_end - x) - '0') {
				pandigital |= 1 << (*(numstr_end - x) - '1');
			}
		}

		if (pandigital != 0x1FF) {
			continue;
		}

		printf("i => %lu\n", i);
		break;
	}

	free(numstr);
	mpz_clear(fib0);
	mpz_clear(fib);

	return 0;
}

