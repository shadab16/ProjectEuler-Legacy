#include <stdio.h>
#include <math.h>

int main(void) {

	/* H(143) = 40755 */
	long long n = 143;
	long long Hn = 0;

	while (1) {
		++n;

		Hn = n * (2*n - 1);
		double n_ = (sqrt(1 + 24*Hn) + 1) / 6;
		double n__ = round(n_);

		if (fabs(n_ - n__) < 1e-8) {
			break;
		}
	}

	printf("Found: %llu\n", Hn);

	return 0;
}

