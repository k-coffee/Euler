#include <stdio.h>
#include <math.h>

#define MAX 1000
//#define MAX 13

int is_square(int d) {
	int i;

	for (i = 1; i <= (int)sqrt(d); i++) {
		if (i * i == d)
			return 0;
	}
	return 1;
}

void main()
{
	unsigned long int max, x, y, d, flag;
	long double tmp;
	unsigned long int maxd;

	max = 0;
	for (d = MAX; d >= 1; d--) {
		if (is_square(d) != 0) {
			flag = 0;
			for (x = 2; flag == 0; x++) {
/*
				for (y = 1; y < x; y++) {
					if (x * x - d * y * y == 1)
						flag = 1;
				}
				if (flag)
					if (max < x) {
						max = x;
						maxd = d;
					}
*/
				y = x * x - 1;
				tmp = y / (double)d;
				tmp = sqrt(tmp);
				if (ceil(tmp) == floor(tmp)) {
					if (max < x) {
						max = x;
						maxd = d;
					}
printf("%d :  x: %d y: %d\n", d, x, (int)tmp);
					break;
				}
			}
		}
	}

	printf("ans: %lu, %lu\n", maxd, max);
}
