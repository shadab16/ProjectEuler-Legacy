#include <stdio.h>
#include <math.h>

long breakcount(const int n) {

	if (n == 2) {
		return 1;
	}

	return c;
}

int main(void) {

	const int n = 5;
	long count = breakcount(n);

	printf("Different Ways: %ld\n", count);
}

/*
f(3)

3::	1 + 1 + 1
2::	2 + 1

f(4)

4::	1 + 1 + 1 + 1
3::	2 + 1 + 1
2::	3 + 1
	2 + 2

f(5)

5::	1 + 1 + 1 + 1 + 1
4::	2 + 1 + 1 + 1
3::	3 + 1 + 1
	2 + 2 + 1
2::	4 + 1
	3 + 2

f(6)

6::	1 + 1 + 1 + 1 + 1 + 1
5::	2 + 1 + 1 + 1 + 1
4::	3 + 1 + 1 + 1
	2 + 2 + 1 + 1
3::	4 + 1 + 1
	3 + 2 + 1
	2 + 2 + 2
2::	5 + 1
	4 + 2
	3 + 3
*/
