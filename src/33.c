#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int sum_n = 1;
	int sum_d = 1;

	for (int num = 11; num < 99; ++num) {
		for (int den = 11; den < 99; ++den) {
			if (num >= den || num % 10 == 0 || den % 10 == 0) continue;

			int num_1 = num / 10;
			int num_2 = num % 10;

			int den_1 = den / 10;
			int den_2 = den % 10;

			if (num_1 == den_1) {
				if (num * den_2 == num_2 * den) {
					sum_n *= num_2;
					sum_d *= den_2;
					printf("%-2d/%-2d ~ %d/%d\n", num, den, num_2, den_2);
					continue;
				}
			}

			if (num_1 == den_2) {
				if (num * den_1 == num_2 * den) {
					sum_n *= num_2;
					sum_d *= den_1;
					printf("%-2d/%-2d ~ %d/%d\n", num, den, num_2, den_1);
					continue;
				}
			}

			if (num_2 == den_1) {
				if (num * den_2 == num_1 * den) {
					sum_n *= num_1;
					sum_d *= den_2;
					printf("%-2d/%-2d ~ %d/%d\n", num, den, num_1, den_2);
					continue;
				}
			}

			if (num_2 == den_2) {
				if (num * den_1 == num_1 * den) {
					sum_n *= num_1;
					sum_d *= den_1;
					printf("%-2d/%-2d ~ %d/%d\n", num, den, num_1, den_1);
					continue;
				}
			}			
		}
	}

	printf("Fraction => %d/%d\n", sum_n, sum_d);

	return 0;
}

