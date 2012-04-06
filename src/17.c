#include <stdio.h>

int getWordLength(int index)
{
	int length = 0;
	int debug = 0;

	int ones[9] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
	int spec[9] = {6, 6, 8, 8, 7, 7, 9, 8, 8};
	int tens[9] = {3, 6, 6, 5, 5, 5, 7, 6, 6};

	char c_ones[9][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char c_spec[9][10] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char c_tens[9][10] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	if (index == 1000)
	{
		if (debug) printf("one thousand\n");

		return 11; /* one thousand */
	}

	if (index / 100 != 0)
	{
		if (debug) printf("%s hundred ", c_ones[index/100-1]);

		length += ones[(index / 100) - 1]; /* The actual number */
		length += 7;                       /* Hundred */

		/* get rid of the hundredth part */
		index -= (index / 100) * 100;

		if (index)
		{
			if (debug) printf("and ");

			length += 3;               /* and */
		}
	}

	if (index / 10 != 0)
	{
		if (index / 10 == 1)
		{
			if (index % 10 == 0)
			{
				if (debug) printf("%s ", c_tens[0]);

				length += tens[0];
			}
			else
			{
				if (debug) printf("%s ", c_spec[index%10-1]);

				length += spec[(index % 10) - 1];
			}

			return length;
		}
		else
		{
			if (debug) printf("%s ", c_tens[index/10-1]);

			length += tens[(index / 10) - 1];
		}

		/* get rid of the tenth part */
		index -= (index / 10) * 10;
	}

	if (index)
	{
		if (debug) printf("%s ", c_ones[index-1]);

		length += ones[index - 1];
	}
	
	return length;
}

int main(void)
{
	long length = 0;

	for (int i = 1; i <= 1000; ++i)
	{
		length += getWordLength(i);
	}

	printf("%d\n", length);

	return 0;
}
