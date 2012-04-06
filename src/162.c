#include <stdio.h>

int main(void) {


	return 0;
}

/*
F E D C B A 9 8 7 6 5 4 3 2 1 0
          A 9 8 7 6 5 4 3 2 1 0
^ ^ ^ ^ ^
| | | | |
| | | | |
| | | | |
| | | | |
| | | | |
| | | | +---- [0, F]
| | | |
| | | +------ [0, F]
| | |
| | +-------- [0, F]
| |
| +---------- [0, F]
|
+------------ [0, F]

(16 * 16 * 16 * 16 * 16) * 11!
1048576 * 11!

-> 418557984768

Minus all permutations of lower digits when 0 is at first position
and the number contains only 11 digits
*/
