#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long calculate_cost_(long n, long offset, long limit, const int depth) {

	if (limit == offset + 1) {
		/*printf("%*s", 8*depth, " ");
		printf("[%ld, %ld] return: %ld\n", offset, limit, offset);*/
		return offset;
	}

	if (limit == offset) {
		/*printf("%*s", 8*depth, " ");
		printf("[%ld, %ld] dead-end: %ld\n", limit, offset, 0L);*/
		return 0;
	}

	if (limit - offset < 8) {
		/* Take a guess */
		long question = offset + lround(0.625 * (limit - offset));

		/*printf("%*s", 8*depth, " ");
		printf("[%ld, %ld] question: %ld\n", offset, limit, question);*/

		long long cost1 = calculate_cost_(n, offset, question - 1, depth+1);
		long long cost2 = calculate_cost_(n, question + 1, limit, depth+1);

		return question + (cost1 > cost2 ? cost1 : cost2);
	}

	long long cost = 10e15;

	for (long question = offset+1; question < limit; ++question) {

		/*printf("%*s", 8*depth, " ");
		printf("[%ld, %ld] question: %ld\n", offset, limit, question);*/

		long long cost1 = calculate_cost_(n, offset, question - 1, depth+1);
		long long cost2 = calculate_cost_(n, question + 1, limit, depth+1);
		long long cost_ = question + (cost1 > cost2 ? cost1 : cost2);

		if (cost_ < cost) cost = cost_;
	}
	return cost;
}

long long calculate_cost(long n) {

	if (n <= 0) {
		return 0;
	}

	return calculate_cost_(n, 1, n, 1);
}

int main(void) {

	long long cost = calculate_cost(30);
	printf("Cost: %lld\n", cost);

	return 0;
}

