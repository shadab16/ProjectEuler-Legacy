#include <stdio.h>
#include <stdlib.h>

long long path_count(long long *cache, int grid_size, int x, int y) {

	if (x < grid_size && y < grid_size) {

		int idx = (y * grid_size) + x;

		if (cache[idx] == 0) {
			cache[idx] = path_count(cache, grid_size, x+1, y) +
				path_count(cache, grid_size, x, y+1);
		}

		return cache[idx];
	}

	return 1;
}

int main(void) {

	const int grid_size = 20;

	long long *cache = calloc(grid_size * grid_size * sizeof(long long), sizeof(long long));
	long long paths = path_count(cache, grid_size, 0, 0);

	free(cache);

	printf("Path Count: %lld\n", paths);

	return 0;
}

