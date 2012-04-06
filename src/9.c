#include <stdio.h>

int main(void) {

	for (int a = 1; a < 1000; ++a) {
		for (int b = 1; b < 1000; ++b) {

			int c = 1000 - a - b;
			
			if (a*a + b*b == c*c) {
				printf("a = %d, b = %d, c = %d, Product = %ld", a, b, c, (long) a*b*c);
				return 0;
			}
		}
	}

	return 0;
}
