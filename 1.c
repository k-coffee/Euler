#include <stdio.h>

void main(int argc, char *argv[])
{
	int i, j, sum;
	int flag;

	sum = 0;
	for(i = 1; i < 1000; i++) {
		if (i % 3 == 0)
			sum += i;
		if (i % 5 == 0)
			sum += i;
		if (i % 15 == 0)
			sum -= i;
	}
	printf("ans: %d\n", sum);
}
