#include <stdio.h>
#include <string.h>

int main(void) {

	char filedata[16345+1] = "";

	FILE* handle = fopen("resources/words.txt", "r");
	if (16345 != fread(filedata, 1, 16345, handle)) {
		return 1;
	}
	fclose(handle);

	char* pos = strtok(filedata, "\",");
	while (pos != 0) {
		
		pos = strtok(0, "\",");
	}

	return 0;
}

