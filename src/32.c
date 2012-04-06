#include <stdio.h>

int is_pandigital(unsigned int n) {
	unsigned int flag = 0;
	while (n) {
		if (n % 10) flag |= 1 << ((n % 10) - 1);
		n /= 10;
	}
	return (flag == 0x1FF);
}

int main(void) {

	unsigned int set[9999] = {0};
	unsigned long sum = 0;

	for (unsigned int a = 2; a <= 9; ++a) {
		for (unsigned int bcde = 1234; bcde <= 4987; ++bcde) {
			unsigned int prod = a * bcde;
			if (prod >= 9999 || set[prod]) {
				continue;
			}
			if (is_pandigital(a * 1e8 + bcde * 1e4 + prod)) {
				set[prod] = 1;
				sum += prod;
			}
		}
	}

	for (unsigned int ab = 12; ab <= 98; ++ab) {
		for (unsigned int cde = 123; cde <= 987; ++cde) {
			unsigned int prod = ab * cde;
			if (prod >= 9999 || set[prod]) {
				continue;
			}
			if (is_pandigital(ab * 1e7 + cde * 1e4 + prod)) {
				set[prod] = 1;
				sum += prod;
			}
		}
	}

	printf("%lu\n", sum);

	return 0;
}

