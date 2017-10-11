#include <stdio.h>

void main()
{
	int i, sum, sum2;

	sum = sum2 = 0;
	for (i = 1; i <= 100; i++) {
		sum += i*i;
		sum2 += i;
	}
	printf("ans: %d\n", sum);
	printf("ans: %d\n", sum2);
	printf("ans: %d\n", (sum2 * sum2 - sum));
}
