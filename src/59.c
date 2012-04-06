#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char filedata[3205] = "";
	int codes[1600] = {0};

	FILE* handle = fopen("resources/cipher1.txt", "r");

	if (3204 != fread(filedata, 1, 3204, handle)) {
		printf("Problem reading file.\n");
		fclose(handle);
		return -1;
	}
	fclose(handle);

	char key[4] = "god";
	int ascii_sum = 0;

	int* code_ = codes;
	char* pos = strtok(filedata, ",");
	while (pos != 0) {
		*code_ = atoi(pos);
		pos = strtok(0, ",");
		ascii_sum += (*code_) ^ key[(code_ - codes) % 3];
		printf("%c", (*code_) ^ key[(code_ - codes) % 3]);
		++code_;
	}

	printf("\n\nSum: %d\n", ascii_sum);

	return 0;
}

