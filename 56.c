#include <stdio.h>
#define MAX 200

void calc(int a, int b, int x[MAX])
{
	int i, j, adder, tmp;

	for (i = 0; i < MAX; i++)
		x[i] = 0;

	x[0] = a;

	for (i = 0; i < b; i++) {
		adder = 0;
		for (j = 0; j < MAX; j++) {
			tmp = x[j] * a;
			tmp += adder;
			x[j] = tmp % 10;
			adder = tmp / 10;
		}
	}
}

int count_keta(int x[MAX])
{
	int i, count;

	for (i = 0, count = 0; i < MAX; i++) {
		count += x[i];
	}
	return count;
}

void main()
{
	int a, b, tmp, max;
	int x[MAX];
	max = 0;
	for (a = 1; a < 100; a++) {
		for (b = 1; b < 100; b++) {
			calc(a, b, x);
			tmp = count_keta(x);

			if (tmp > max) {
				max = tmp;
			}
		}
	}
	printf("ans: %d\n", max);
}
