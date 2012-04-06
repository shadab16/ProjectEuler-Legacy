#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void) {

	unsigned long basenum = 2;
	unsigned long power = 1000;

	mpz_t num;
	mpz_init(num);

	mpz_ui_pow_ui(num, basenum, power);	

	char* numstr = mpz_get_str(0, 10, num);

	int digitsum = 0;
	for (char* digit = numstr; *digit; ++digit) {
		digitsum += (*digit) - '0';
	}
	printf("Sum of digits: %d\n", digitsum);

	free(numstr);
	mpz_clear(num);

	return 0;
}

