#include <stdio.h>
#include <stdlib.h>

int main(void) {

	size_t limit = 1e6;

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

	size_t max_n = 0;
	double max_nphi = 0.0;

	for (size_t n = 2; n <= limit; ++n) {
		double nphi = (double) n / phi[n];
		if (nphi > max_nphi) {
			max_n = n;
			max_nphi = nphi;
		}
	}

	printf("n: %zu	n/φ(n): %.3f\n", max_n, max_nphi);

	free(phi);

	return 0;
}

