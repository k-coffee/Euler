#include <stdio.h>

/*
int kaijo(int x)
{
	
}
*/

unsigned long int ncr(int n, int r)
{
	unsigned long int i, x, tmp;

	x = 1;
	tmp = 1;
	for (i = n; i > n - r; i--) {
		tmp *= i;
		if (tmp % x == 0 && x <= r) {
			tmp /= x;
			x++;
		} 
		if (x > r && tmp >= 1000000)
			return 1000000;
	}

	i = 1;
//	printf("%u\n", tmp);
//	printf("%d\n", x);
	for (; x <= r; x++)  {
		if (tmp % x == 0)
			tmp /= x;
		else
			i *= x;
	}

	tmp /= i;

	return tmp;
}

void main()
{
	int sum, n, r, i, j;

	sum = 0;
//n=23;
//	printf("5: %ld\n", ncr(99, 7));
//	printf("5: %ld\n", ncr(99, 6));

	for (n = 100; n > 0; n--) {
		for (r = n; r > 0; r--) {
			if (ncr(n, r) >= 1000000) {
				sum++;
				if (r == 1)
					sum++;
			}
		}
	}

	printf("ans: %d\n", sum);
}
