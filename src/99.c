#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {

	char filedata[14883+1] = "";

	FILE* handle = fopen("resources/base_exp.txt", "r");
	if (14883 != fread(filedata, 1, 14883, handle)) {
		return 1;
	}
	fclose(handle);

	double maxval = 0.0;
	unsigned int maxline = 0;

	char* delim = ",\n\r";
	unsigned int line = 1;
	for (char* pos = strtok(filedata, delim); pos != 0; ++line) {

		unsigned long base = atol(pos); pos = strtok(0, delim);
		unsigned long exp  = atol(pos); pos = strtok(0, delim);

		double val = exp * log10(base);
		if (val > maxval) {
			maxval = val;
			maxline = line;
		}
	}

	printf("%u\n", maxline);

	return 0;
}

