#include <stdio.h>

int kaibun_ten(int x)
{
	int i, j, c, tmp;
	int y[8];

	c = 0;
	while(x / 10 != 0) {
		tmp = x % 10;
		x /= 10;
		y[c] = tmp;
		c++;
	}
	y[c] = x % 10;

	for(i = 0; i <= c / 2; i++) {
		if (y[i] != y[c-i])
			return 0;
	}

	return 1;
}

int kaibun_binary(int x)
{
	int i, c;
	int b_size = sizeof(int) * 8;
	int bit = 1;
	int y[b_size];

	c = 0;

	for(i = 0; i < b_size; i++) {
		if (x & bit)
			y[c] = 1;
		else
			y[c] = 0;
		c++;
		bit <<= 1;
	}

	while(y[c] != 1)
		c--;

	for(i = 0; i <= c / 2; i++) {
		if (y[i] != y[c-i])
			return 0;
	}

	return 1;
}

void main()
{
	int i, sum;

	sum = 0;

	for(i = 1; i < 1000000; i++)
		if (kaibun_ten(i) == 1)
			if (kaibun_binary(i) == 1)
				sum += i;

	printf("ans: %d\n", sum);
}
