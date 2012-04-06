#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point {
	int x;
	int y;
} POINT;

unsigned int contains_origin(POINT* a, POINT* b, POINT* c) {

	double x1 = a->x, x2 = b->x, x3 = c->x;
	double y1 = a->y, y2 = b->y, y3 = c->y;

	double lambda1 = (double) (-x3 * (y2 - y3) + -y3 * (x3 - x2)) / ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
	double lambda2 = (double) (-x3 * (y3 - y1) + -y3 * (x1 - x3)) / ((y3 - y1) * (x2 - x3) + (x1 - x3) * (y2 - y3));
	double lambda3 = 1 - lambda1 - lambda2;

	return (lambda1 > 0 && lambda1 < 1) && (lambda2 > 0 && lambda2 < 1) && (lambda3 > 0 && lambda3 < 1);
}

/* Reference: Barycentric Coordinates */
/* http://en.wikipedia.org/wiki/Barycentric_coordinates_%28mathematics%29 */

int main(void) {

	char filedata[27383+1] = "";

	FILE* handle = fopen("resources/triangles.txt", "r");
	if (27383 != fread(filedata, 1, 27383, handle)) {
		return 1;
	}
	fclose(handle);

	POINT p[3000];

	const char delim[] = ",\n\r";
	char* digits = strtok(filedata, delim);

	for (size_t i = 0; i < 3000; ++i) {
		p[i].x = atoi(digits); digits = strtok(0, delim);
		p[i].y = atoi(digits); digits = strtok(0, delim);
	}

	unsigned int count = 0;

	for (size_t i = 0; i < 3000; i += 3) {
		if (contains_origin(p + i, p + i + 1, p + i + 2)) {
			++count;
		}
	}

	printf("%u\n", count);

	return 0;
}

