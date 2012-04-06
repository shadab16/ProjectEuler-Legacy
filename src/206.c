#include <stdio.h>

int main(void) {

	for (unsigned long long i = 1010101030; i < 1389026630; ) {

		unsigned long long n = i * i;
		unsigned int digit = 9;

		while (n /= 100) {
			if (n % 10 != digit--) {
				break;
			}
		}

		if (!n) {
			printf("%llu\n", i);
			break;
		}

		i += (i % 100 == 30) ? 40 : 60;
	}

	return 0;
}

