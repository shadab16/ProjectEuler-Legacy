#include <stdio.h>

int main(void) {

	unsigned long sum = 0;

	for (unsigned int i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	printf("%lu\n", sum);

	return 0;
}

