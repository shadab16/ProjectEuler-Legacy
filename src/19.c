#include <stdio.h>

/* Reference: http://www.jimloy.com/math/day-week.htm */
/* W = (century + year + leap + month + date) % 7 */

int main(void) {

	const int mval[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
	int count = 0;

	for (int year = 1901; year <= 2000; ++year) {

		/* offset for taking into account different centuries */
		const int offset = (year == 2000) ? 6 : 1;

		for (int month = 1; month <= 12; ++month) {

			/* leap days since the beginning of century */
			int leap = (int) ((year % 100) / 4) + (year % 400 == 0);

			/* adjust leap count for Jan & Feb on leap years */
			if (month <= 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
				--leap;
			}

			if ((year % 100 + leap + mval[month-1] + offset) % 7 == 0) {
				++count;
				printf(":: %2d / %d\n", month, year);
			}
		}
	}

	printf("First Sunday count => %d\n", count);

	return 0;
}

