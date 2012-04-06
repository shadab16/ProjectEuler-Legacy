#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_str(const void* a, const void* b) {

	return *(char*) a - *(char*) b;
}

int compare_str_array(const void* a, const void* b) {

	return strcmp((char*) a, (char*) b);
}

int main(void) {

	/* 216, 10077696,	464, 99897344,		249 elements,	8 digits */
	/* 465, 100544625,	999, 997002999,		535 elements,	9 digits */
	/* 1000, 1000000000,	2154, 9993948264,	1155 elements,	10 digits */
	/* 2155, 10007873875,	4641, 99961946721,	2487 elements,	11 digits */
	/* 4642, 100026577288,	9999, 999700029999,	5358 elements,	12 digits */

	/* e ^ (x/3 ln 10) */

	char cubes[5358][13] = {""};
	char sorted[5358][13] = {""};

	const int offset = 4642;
	const int data_count = sizeof(cubes) / sizeof(*cubes);
	const int data_size = sizeof(*cubes);

	for (int i = 0, n = offset; i < data_count; ++i, ++n) {
		snprintf(cubes[i], data_size, "%lld", (long long) n * n * n);
		qsort(cubes[i], data_size - 1, sizeof(char), compare_str);
	}

	memcpy(sorted, cubes, sizeof(sorted));
	qsort(sorted, data_count, data_size, compare_str_array);

	char* previous = 0;
	for (int i = 0, count = 1; i < data_count; ++i) {
		if (!previous || strcmp(previous, sorted[i])) {
			previous = sorted[i];
			count = 1;
		} else if (++count >= 5) {
			break; /* Found it! */
		}
	}

	for (int i = 0, n = offset; i < data_count; ++i, ++n) {
		if (strcmp(cubes[i], previous) == 0) {
			printf("n => %d, %lld\n", n, (long long) n * n * n);
		}
	}

	return 0;
}

