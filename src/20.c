#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void) {

	unsigned long basenum = 100;

	mpz_t num;
	mpz_init(num);

	mpz_fac_ui(num, basenum);

	char* strnum = mpz_get_str(0, 10, num);
	int digitsum = 0;
	for(char* digit = strnum; *digit != 0; ++digit) {
		digitsum += *digit - '0';
	}
	printf("Sum of digits: %d\n", digitsum);

	free(strnum);
	mpz_clear(num);

	return 0;
}
