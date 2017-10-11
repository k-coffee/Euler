#include <stdio.h>

#define MAX 500

int keta(int x[MAX])
{
	int i;

	i = MAX - 1;

	while (x[i] == 0) {
		i--;
	}
	return i;
}

void swap_a(int x[MAX], int y[MAX])
{
	int i, z;

	for (i = 0; i < MAX; i++) {
		z = x[i];
		x[i] = y[i];
		y[i] = z;
	}
}

void add_a(int x[MAX], int y[MAX])
{
	int i, adder, tmp;

	adder = 0;
	for (i = 0; i < MAX; i++) {
		tmp = x[i] + y[i];
		tmp += adder;
		x[i] = tmp % 10;
		adder = tmp / 10;
	}
}

void double_a(int x[MAX], int y[MAX])
{
	int i, adder, tmp, z[MAX];

	adder = 0;
	for (i = 0; i < MAX; i++) {
		tmp = y[i] * 2;
		tmp += adder;
		z[i] = tmp % 10;
		adder = tmp / 10;
	}

	add_a(x, z);
}

void copy_a(int x[MAX], int y[MAX])
{
	int i;

	for (i = 0; i < MAX; i++)
		x[i] = y[i];
}

void main()
{
	int a[MAX], b[MAX], c[MAX];
	int i, count;

	for (i = 0; i < MAX; i++) {
		a[i] = 0;
		b[i] = 0;
	}

	a[0] = 1;
	b[0] = 2;
	count = 0;
	for (i = 0; i <= 1000; i++) {
		double_a(a, b);
		swap_a(a, b);
		copy_a(c, a);
		add_a(c, b);
		
		if (keta(c) > keta(b))
			count++;
	}

	printf("ans: %d\n", count);
}
