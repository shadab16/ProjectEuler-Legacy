#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(void) {

	mpz_t num;
	mpz_init(num);

	for (unsigned long n = 1000; ; ++n) {

		mpz_fib_ui(num, n);
		char* numstr = mpz_get_str(0, 10, num);

		if (strlen(numstr) == 1000) {
			printf("%lu\n", n);
			free(numstr);
			break;
		}
		free(numstr);
	}

	mpz_clear(num);

	return 0;
}

