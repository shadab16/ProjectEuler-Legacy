#include <stdio.h>
#include <string.h>
#include <math.h>

int triangle_word(const char* letter) {

	int Tn = 0;
	for (; *letter; ++letter) {
		Tn += *letter - 'A' + 1;
	}

	double n = (sqrt(1 + 8 * Tn) - 1) / 2;
	if (fabs(n - round(n)) < 1e-8) {
		return 1;
	}
	return 0;
}

int main(void) {

	char filedata[16345+1] = "";

	FILE* handle = fopen("resources/words.txt", "r");
	if (16345 != fread(filedata, 1, 16345, handle)) {
		return 1;
	}
	fclose(handle);

	char* pos = strtok(filedata, "\",");
	int words = 0;
	while (pos != 0) {
		if (triangle_word(pos)) {
			++words;
		}
		pos = strtok(0, "\",");
	}
	printf("Triangle Words: %d\n", words);

	return 0;
}

