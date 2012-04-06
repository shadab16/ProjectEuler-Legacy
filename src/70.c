#include <stdio.h>
#include <stdlib.h>
#include "euler.h"

int main(void) {

	size_t limit = 1e7;

	unsigned long* phi = malloc((limit + 1) * sizeof(unsigned long));
	phi[0] = phi[1] = 0;
	for (size_t i = 0; i <= limit; ++i) {
		phi[i] = i;
	}

	for (size_t i = 2; i <= limit; ++i) {
		if (phi[i] == i) {
			for (size_t j = i; j <= limit; j += i) {
				phi[j] = (phi[j] / i) * (i - 1);
			}
		}
	}

	size_t min_n = 0;
	double min_nphi = 1e7;

	for (size_t n = 2; n <= limit; ++n) {
		double nphi = (double) n / phi[n];
		if (nphi < min_nphi && sort_digits(n) == sort_digits(phi[n])) {
			min_n = n;
			min_nphi = nphi;
		}
	}

	printf("n: %zu	n/φ(n): %f\n", min_n, min_nphi);

	free(phi);

	return 0;
}

