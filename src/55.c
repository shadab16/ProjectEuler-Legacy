#include <stdio.h>

unsigned long long reverse(unsigned long long n) {
	unsigned long long reverse = 0;
	while (n > 0) {
		reverse = (reverse * 10) + (n  % 10);
		n /= 10;
	}
	return reverse;
}

int is_lychrel(unsigned long long n) {

	for (int i = 0; i < 50; ++i) {
		n = n + reverse(n);
		if (n == reverse(n)) {
			return 0;
		}
	}

	return 1;
}

int main(void) {

	const int limit = 10000;
	int count = 0;

	for (int i = 1; i < limit; ++i) {
		if (is_lychrel(i)) {
			++count;
		}
	}

	printf("Lychrel numbers: %d\n", count);

	return 0;
}

