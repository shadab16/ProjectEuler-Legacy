#include <stdio.h>

int main(void) {

	char fraction[1000010] = "";
	char* digit = fraction + 1;

	unsigned long n = 1;

	while (digit - fraction <= 1000000) {
		int pos = sprintf(digit, "%lu", n++);
		digit += pos;
	}	

	printf("%d\n",
		(fraction[1] - '0') * (fraction[10] - '0') *
		(fraction[100] - '0') * (fraction[1000] - '0') *
		(fraction[10000] - '0') * (fraction[100000] - '0') *
		(fraction[1000000] - '0')
	);

	return 0;
}

