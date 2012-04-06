#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long factorial(const unsigned int n) {

	unsigned long long f = 1;
	for (unsigned int i = 1; i <= n; ++i) {
		f *= i;
	}
	return f;
}

void permute_(const char* const letters, char* const perms, const size_t index, const size_t length) {

	if (index >= length) return;

	const size_t offset = factorial(length - index - 1);

	for (size_t i = 0; i < strlen(letters); ++i) {

		for (size_t j = offset * i; j < offset * (i + 1); ++j) {
			*(perms + (j * (length + 1)) + index) = letters[i];
		}

		if (length - index == 1) continue;

		char* const letters_ = calloc(length - index, sizeof(char));
		strncpy(letters_, letters, i);
		strncpy(letters_ + i, letters + i + 1, length - index - i);
		
		permute_(letters_, perms + (offset * i * (length + 1)), index + 1, length);

		free(letters_);
	}
}

void permute(const char* const letters, char* const perms) {

	permute_(letters, perms, 0, strlen(letters));
}

int main(void) {

	const char letters[] = "0123456789";
	char* perms = calloc(factorial(sizeof(letters) - 1) * sizeof(letters), sizeof(char));

	permute(letters, perms);

	printf("%s", perms + ((1000000 - 1) * sizeof(letters)));

	free(perms);

	return 0;
}

