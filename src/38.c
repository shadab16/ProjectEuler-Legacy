#include <stdio.h>

int main(void) {

	unsigned long maxpan = 0;

	for (unsigned int i = 9123; i <= 9876; ++i) {

		unsigned long number = (i * 1e5) + (i * 2);
		unsigned long flag = 0;

		for (unsigned long n = number; n; n /= 10) {
			if (n % 10) {
				flag |= 1 << ((n % 10) - 1);
			}
		}

		if (flag == 0x1FF && number > maxpan) {
			maxpan = number;
		}
	}

	printf("%lu\n", maxpan);

	return 0;
}

