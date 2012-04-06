#include <stdio.h>
#include <stdlib.h>

int main(void) {

	const unsigned int primes[] = {
		  2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
		 73,  79,  83,  89,  97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
		179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
		283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
		419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
		547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
		661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
	};

	const size_t limit = 150000;
	const size_t sieves = sizeof(primes) / sizeof(*primes);

	unsigned int* factors = calloc(limit * sieves * sizeof(unsigned int), sizeof(unsigned int));

	for (size_t sieve = 0; sieve < sieves; ++sieve) {
		unsigned int base = primes[sieve];
		for (size_t factor = 1; factor * base < limit; ++factor) {
			*(factors + (sieve * limit) + (base * factor)) = 1;
		}
	}

	const unsigned int target = 4;
	unsigned int num = 0, consecutive = 0;

	for (size_t i = 1; i < limit; ++i) {
		unsigned int count = 0;
		for (size_t sieve = 0; sieve < sieves; ++sieve) {
			if (*(factors + (sieve * limit) + i)) {
				++count;
			}
			if (count > target) {
				break;
			}
		}
		if (count == target) {
			if (++consecutive == target) {
				num = i - target + 1;
				break;
			}
		} else {
			consecutive = 0;
		}
	}

	printf("%u\n", num);

	free(factors);

	return 0;
}

