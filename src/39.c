#include <stdio.h>
#include <math.h>

int count_solutions(const int p) {

	int count = 0;

	for (int a = 1; a < p/2; ++a) {
		for (int b = a; b < p/2; ++b) {
			double h = sqrt(a*a + b*b);
			if (a + b + h == p && fabs(h - round(h)) < 1e-8) {
				++count;
			}
		}
	}

	return count;
}

int main(void) {

	int max_p = 0, max_sol = 0;

	for (int p = 1000; p > 500; --p) {
		int sol = count_solutions(p);
		if (sol > max_sol) {
			max_sol = sol;
			max_p = p;
		}
	}

	printf("Max P: %d\n", max_p);

	return 0;
}

