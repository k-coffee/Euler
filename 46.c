#include <stdio.h>

int prime(int x)
{
	int i;
	i = 3;
	if (x == 2)
		return 1;
	if (x == 1)
		return 0;

	for (i = 3; i < x; i += 2)
		if (x % i == 0)
			return 0;
	return 1;
}

int isdouble(int x)
{
	int i;

	x /= 2;
	i = 1;
	while ((i * i) <= x) {
		if ((i * i) == x)
			return 1;
		i++;
	}
	return 0;
}

void main()
{
	int i, j, flag;

	i = 3;
	while (1) {
		if (prime(i) == 0) {
			flag = 0;
			for (j = 1; j < i; j += 2) {
				if (prime(j) == 1) {
					if (isdouble(i - j) == 1) {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0) {
				printf("ans: %d\n", i);
				exit(0);
			}
		}
		i += 2;
	}
}
