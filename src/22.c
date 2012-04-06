#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_names(const void* a, const void* b) {

	return strcmp((char*) a, (char*) b);
}

int main(void) {

	char filedata[46447+1] = "";

	FILE* handle = fopen("resources/names.txt", "r");
	if (46447 != fread(filedata, 1, 46447, handle)) {
		return 1;
	}
	fclose(handle);

	char names[5163][12] = {""};
	const char delim[] = "\",";

	int idx = 0;
	for (char* name = strtok(filedata, delim); name; name = strtok(0, delim)) {
		strncpy(names[idx++], name, 11);
	}

	qsort(names, sizeof(names) / sizeof(*names), sizeof(*names), compare_names);

	unsigned long long score = 0;

	for (unsigned int i = 0; i < sizeof(names) / sizeof(*names); ++i) {
		unsigned long score_ = 0;
		for (char* letter = names[i]; *letter; ++letter) {
			score_ += *letter - 'A' + 1;
		}
		score += score_ * (i + 1);
	}

	printf("%llu\n", score);

	return 0;
}

