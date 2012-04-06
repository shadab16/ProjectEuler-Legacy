#include <stdio.h>
#include <math.h>

double fx(const double x) {

	return floor(pow(2, 30.403243784 - (x * x))) * 1e-9;
}

double sequence(const long long n) {

	if (n == 0) {
		return -1;
	}

	return fx(sequence(n - 1));
}

int main(void) {

	const int n = 516;

	printf("%.12f\t%.12f\n----------|\t----------|\n%.12f\t%.12f\n\n",
		sequence(n + 0), sequence(n + 1), sequence(n + 2), sequence(n + 3)
	);

	printf("%.9f\n", sequence(n) + sequence(n + 1));

	return 0;
}

