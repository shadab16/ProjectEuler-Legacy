#include <stdio.h>
#include <string.h>
#include <gmp.h>

typedef struct convergent {
	mpz_t n; /* numerator */
	mpz_t d; /* denominator */
} convergent;

convergent get_fraction(unsigned int limit) {

	convergent f;
	mpz_init_set_ui(f.n, 0);
	mpz_init_set_ui(f.d, 1);

	if (limit < 1) {
		return f;
	}

	mpz_set_ui(f.n, 1);
	mpz_set_ui(f.d, 2);

	convergent f2 = get_fraction(limit - 1);

	/* f.n = f.n * f2.d */
	/* f.d = (f.d * f2.d) + f2.n */

	mpz_mul(f.n, f.n, f2.d);
	mpz_mul(f.d, f.d, f2.d);
	mpz_add(f.d, f.d, f2.n);

	mpz_clear(f2.n);
	mpz_clear(f2.d);

	return f;
}

convergent get_convergent(unsigned int expansions) {

	convergent c = get_fraction(expansions);

	/* c.n = (base * c.d) + c.n */
	mpz_addmul_ui(c.n, c.d, 1);

	return c;
}

int main(void) {

	const unsigned int expansions = 1000;
	char numstr[2][1000] = {"", ""};

	unsigned int count = 0;
	for (unsigned int i = 1; i <= expansions; ++i) {
		convergent c = get_convergent(i);

		mpz_get_str(numstr[0], 10, c.n);
		mpz_get_str(numstr[1], 10, c.d);

		if (strlen(numstr[0]) > strlen(numstr[1])) {
			++count;
		}

		mpz_clear(c.n);
		mpz_clear(c.d);
	}
	printf("%u\n", count);

	return 0;
}

