#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

typedef struct convergent {
	mpz_t n; /* numerator */
	mpz_t d; /* denominator */
} convergent;

convergent get_fraction(int* repeats, int current, int limit) {

	convergent f;
	mpz_init_set_ui(f.n, 0);
	mpz_init_set_ui(f.d, 1);

	if (limit <= 1) {
		return f;
	}

	mpz_set_ui(f.n, 1);
	mpz_set_ui(f.d, repeats[current]);

	if (repeats[++current] == 0) {
		current = 0;
	}

	convergent f2 = get_fraction(repeats, current, limit - 1);

	/* f.n = f.n * f2.d */
	/* f.d = (f.d * f2.d) + f2.n */

	mpz_mul(f.n, f.n, f2.d);
	mpz_mul(f.d, f.d, f2.d);
	mpz_add(f.d, f.d, f2.n);

	mpz_clear(f2.n);
	mpz_clear(f2.d);

	return f;
}

convergent get_convergent(int base, int* repeats, int limit) {

	convergent c = get_fraction(repeats, 0, limit);

	/* c.n = (base * c.d) + c.n */
	mpz_addmul_ui(c.n, c.d, base);

	return c;
}

int main(void) {

	const int Nth = 100;

	int* repeats = calloc(Nth * sizeof(int), sizeof(int));
	for (int i = 0, k = 1; i < Nth; ++i) {
		repeats[i] = ((i - 1) % 3 == 0) ? (2 * k++) : 1;
	}

	convergent c1 = get_convergent(2, repeats, Nth);

	printf("Numerator: ");
	mpz_out_str(stdout, 10, c1.n);

	printf("\nDenominator: ");
	mpz_out_str(stdout, 10, c1.d);

	printf("\n");

	char* numerator = mpz_get_str(0, 10, c1.n);
	int sum = 0;
	for (char* digit = numerator; *digit != 0; ++digit) {
		sum += (*digit) - '0';
	}
	printf("Numerator Sum: %d\n", sum);

	free(numerator);

	mpz_clear(c1.n);
	mpz_clear(c1.d);

	free(repeats);

	return 0;
}

