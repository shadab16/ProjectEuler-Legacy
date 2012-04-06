#include <stdio.h>
#include "gmp.h"

int main(void) {

	unsigned int maxsum = 0;

	mpz_t num;
	mpz_init(num);

	char numstr[200] = "";

	for (unsigned int base = 51; base < 100; ++base) {
		if (base % 10 == 0) {
			continue;
		}
		for (unsigned int exp = 70; exp <= 100; ++exp) {

			mpz_ui_pow_ui(num, base, exp);
			mpz_get_str(numstr, 10, num);

			unsigned int sum = 0;

			for (char* digit = numstr; *digit; ++digit) {
				sum += *digit - '0';
			}
			if (sum > maxsum) {
				maxsum = sum;
			}
		}
	}

	printf("%u\n", maxsum);

	return 0;
}

