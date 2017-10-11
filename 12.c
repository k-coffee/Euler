#include <stdio.h>

int yakusuu(int x)
{
	int i;
	int counter = 0;
	for (i = 1; i <= x; i++)
		if (x % i == 0)
			counter++;

	return counter;
}

void main()
{
	int bak, num, i, j, tmp;
	int counter=2;

	i = 1;
	tmp = 0;

//	while (i <= 10) {
	while (1) {
/*
		for (tmp = 0, j = 1; j <= i; j++)
			tmp += j;
*/
//printf("%d\n", tmp);
		tmp += i;
		i++;
		if (yakusuu(tmp) >= 501)
			break;
	}
printf("%d\n", tmp);
}
