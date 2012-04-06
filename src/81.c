#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static unsigned long sum_cache[80][80] = {{0}};

unsigned long minimal_sum(unsigned int (*num)[80][80], const unsigned int x, const unsigned int y) {

	if (sum_cache[y][x]) {
		return sum_cache[y][x];
	}

	if (x >= 79 && y >= 79) {
		return (*num)[y][x];
	}

	unsigned long minpath = 0;

	if (x >= 79) {
		minpath = minimal_sum(num, x, y + 1);
	} else if (y >= 79) {
		minpath = minimal_sum(num, x + 1, y);
	} else {
		const unsigned long path1 = minimal_sum(num, x + 1, y), path2 = minimal_sum(num, x, y + 1);
		minpath = MIN(path1, path2);
	}

	sum_cache[y][x] = (*num)[y][x] + minpath;
	return sum_cache[y][x];
}

int main(void) {

	char filedata[31386] = "";
	FILE* handle = fopen("resources/matrix.txt", "r");

	if (31385 != fread(filedata, 1, 31385, handle)) {
		fclose(handle);
		return -1;
	}
	fclose(handle);

	unsigned int num[80][80] = {{0}};

	unsigned int* num_ = *num;
	const char* const delim = ",\n\r";
	for (char* pos = strtok(filedata, delim); pos; pos = strtok(0, delim)) {
		*num_ = atoi(pos);
		++num_;
	}

	printf("%lu\n", minimal_sum(&num, 0, 0));

	return 0;
}

