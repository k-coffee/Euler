#include <stdio.h>

unsigned long int tri(unsigned long int n)
{
	return n * (n + 1) / 2;
}

unsigned long int pent(unsigned long int n)
{
	return n * (3 * n - 1) / 2;
}

unsigned long int hexa(unsigned long int n)
{
	return n * (2 * n - 1);
}

void main()
{
	unsigned long int i, j ,k, tmp;

	i = j = k = 144;
	while (1) {
		tmp = hexa(i);
		while (tmp >= pent(j)) {
			if (tmp == pent(j)) {
				printf("ans: %u\n", tmp);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
