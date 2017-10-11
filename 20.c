#include <stdio.h>

#define MAX 1000

void main()
{
	int x[MAX];
	int i, j, up, tmp;

	for(i = 0; i < MAX; i++) {
		x[i] = -1;
	}

	x[0] = 1;
	for(i = 1; i <= 100; i++) {
		up = 0;
		for(j = 0; x[j] != -1; j++) {
			tmp = x[j] * i;
			tmp += up;
			up = tmp / 10;
			x[j] = tmp % 10;
		}
		if (up > 0) {
			tmp = up / 100;
			if (tmp > 0)
				x[j+2] = tmp;
			if (tmp > 0)
				up -= tmp * 100;
			tmp = up / 10;
			x[j + 1] = tmp;
			x[j] = up % 10;
		}
	}

	for(tmp = 0, i = 0; x[i] != -1; i++) {
		tmp += x[i];
	}

	printf("ans: %d\n", tmp);
}
