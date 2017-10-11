#include <stdio.h>

int counter;

int solve(int x[])
{
	int i, j, k;

	j = 0;
	for(i = 0; i < 10; i++) {
		if (x[i] != -1)
			j++;
	}

	if (j == 10) {
		counter++;
		if (counter == 1000000) {
			for(i = 0; i < 10; i++)
				for(k = 0; k < 10; k++)
					if (x[k] == i)
						printf("%d", k);
			printf("\n");
			return 0;
		}
	} else {
		for(i = 0; i < 10; i++)
			if (x[i] == -1) {
				x[i] = j;
				solve(x);
				x[i] = -1;
			}

	}
}

void main()
{
	int i, x[10];

	counter = 0;

	for(i = 0; i < 10; i++) {
		x[i] = -1;
	}

	solve(x);
}
