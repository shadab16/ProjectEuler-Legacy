#include <stdio.h>

/*
 * Check if a number is palindrome
 */
int isPalindrome(long n) {

	long number = n;
	long reverse = 0;

	while (n > 0) {
		reverse = (reverse * 10) + (n  % 10);
		n /= 10;
	}

	return (reverse == number);
}

int main(void) {

	long result = 0;

	for (long i = 999; i >= 100; --i) {
		for (long j = 999; j >= 100; --j) {

			if (i * j > result && isPalindrome(i * j)) {
				result = i * j;
			}
		}
	}

	printf("Resultant Palindrome => %ld\n", result);

	return 0;
}
