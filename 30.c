#include <stdio.h>

int five (int x)
{
	return x * x * x * x * x;
}

void main()
{
	int i, j, tmp, sum, ans;
	int x[6];

	ans = 0;
	for(i = 2; i < 400000; i++) {
		tmp = i;
		x[0] = tmp / 100000;
		tmp -= x[0] * 100000;
		x[1] = tmp / 10000;
		tmp -= x[1] * 10000;
		x[2] = tmp / 1000;
		tmp -= x[2] * 1000;
		x[3] = tmp / 100;
		tmp -= x[3] * 100;
		x[4] = tmp / 10;
		x[5] = tmp % 10;

		sum = 0;
		for (j = 0; j < 6; j++) {
			sum += five(x[j]);
		}
		if (sum == i)
			ans += i;
	}
	printf("ans: %d\n", ans);
}
