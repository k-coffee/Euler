#include <stdio.h>

void add_reverse(int x[100])
{
	int a[100], i, j;
	int sum[100];

	for (i = 0; i < 100; i++) {
		a[i] = -1;
		sum[i] = -1;
	}

	for (i = 99; i >= 0; i--) {
		if (x[i] != 0)
			break;
	}

	for (j = 0; j <= i; j++) {
		a[i-j] = x[j];
	}

	j = 0;
	for (i = 0; a[i] != -1; i++) {
		sum[i] = (j + a[i] + x[i]) % 10;
		j = (a[i] + x[i] + j) / 10;
	}
	if (j != 0) {
		sum[i] = j;
		i++;
	}

	for (j = 0; j < i; j++) {
		x[j] = sum[j];
	}
}

int is_kaibun(int x[100])
{
	int a[100], i, j;

	for (i = 99; i >= 0; i--) {
		if (x[i] != 0)
			break;
	}

	for (j = 0; j <= i/2; j++) {
		if (x[i-j] != x[j])
			return 0;
	}

	return 1;
}

void to_array(int x, int y[100])
{
	int i;

	for (i = 0; i < 100; i++)
		y[i] = 0;

	i = 0;
	while (x / 10 != 0) {
		y[i] = x % 10;
		x /= 10;
		i++;
	}
	y[i] = x;
}

void copy_a(int x[100], int y[100])
{
	int i;
	for (i = 0; i < 100; i++)
		x[i] = y[i];
}

void main()
{
//	unsigned long int i, num, tmp, flag;
	int i, ans, flag, counter;
	int num[100], tmp[100];

	ans = 1;
	counter = 0;
	flag = 0;
	while (ans < 10000) {
		to_array(ans, num);
//		if (is_kaibun(num) == 1) {
			copy_a(tmp, num);
			flag = 0;
			for (i = 1; i < 50; i++) {
				add_reverse(tmp);
				if (is_kaibun(tmp) == 1) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				counter++;
			}
//		}
		ans++;
	}
	printf("ans: %d\n", counter);
}
