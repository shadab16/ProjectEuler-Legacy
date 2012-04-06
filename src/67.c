#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {

	char filedata[15250+1] = "";

	FILE* handle = fopen("resources/triangle.txt", "r");
	if (15250 != fread(filedata, 1, 15250, handle)) {
		return 1;
	}
	fclose(handle);

	int nums[100][100] = {{0}};

	const char delim[] = " \n\r";
	char* digits = strtok(filedata, delim);

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			nums[i][j] = atoi(digits);
			digits = strtok(0, delim);
		}
	}

	for (int i = sizeof(nums) / sizeof(*nums) - 1; i > 0; --i) {
		for (int j = i; j >= 0; --j) {
			nums[i-1][j-1] += MAX(nums[i][j-1], nums[i][j]);
		}
	}

	printf("Maximum Total: %d\n", nums[0][0]);

	return 0;
}

