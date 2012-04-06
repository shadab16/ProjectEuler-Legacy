#include <stdio.h>

long collatz(unsigned long long n) {

	if (n == 1) {
		return 1;
	}

	if (n % 2 == 0) {
		n = n / 2;
	} else {
		n = (n * 3) + 1;
	}

	return 1 + collatz(n);
}

int main(void) {

	long start = 0;
	long count = 0;

	for (long i = 1000000; i > 0; --i) {
		long x = collatz(i);
		if (x > count) {
			count = x;
			start = i;
		}
	}
	
	printf("Longest Chain: %ld\n", count);
	printf("Starting Number: %ld\n", start);

	return 0;
}
