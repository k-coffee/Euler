#include <stdio.h>

int kaibunsuu(int x)
{
	int y[7], i, j;

	for (i = 0; i < 7; i++)
		y[i] = -1;

	if (x >= 1000000) {
		y[0] = x / 1000000;
		x -= 1000000 * y[0];
	}
	if (x >= 100000) {
		y[1] = x / 100000;
		x -= 100000 * y[1];
	} else if(y[0] != -1)
		y[1] = 0;
	if (x >= 10000) {
		y[2] = x / 10000;
		x -= 10000 * y[2];
	} else if(y[1] != -1)
		y[2] = 0;
	if (x >= 1000) {
		y[3] = x / 1000;
		x -= 1000 * y[3];
	} else if(y[2] != -1)
		y[3] = 0;
	if (x >= 100) {
		y[4] = x / 100;
		x -= 100 * y[4];
	} else if(y[3] != -1)
		y[4] = 0;
	if (x >= 10) {
		y[5] = x / 10;
		x -= 10 * y[5];
	} else if(y[4] != -1)
		y[5] = 0;
	y[6] = x;

	for(i = 0; i < 7; i++) {
		if (y[i] != -1) {
			j = i;
			break;
		}
	}

	for(i = 6 - j; i > 0; i-=2) {
		if(y[j] != y[j+i])
			return 1;
		j++;
	}

	return 0;	
}

void main()
{
	int i, j, max;

	max = 0;

	for (i = 100; i < 1000; i++) {
		for (j = 100; j < 1000; j++) {
			if (kaibunsuu(i * j) == 0)
				if (max < i * j)
					max = i * j;
		}
	}
	printf("ans: %d, %d, %d\n", max, i, j);
}
