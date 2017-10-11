#include <stdio.h>

int sosuu(int x)
{
	int tmp;
	for(tmp = 2; tmp < x/2; tmp++) {
		if (x % tmp == 0)
			return 1;
	}
	return 0;
}

void main()
{
	int i, counter;

	for(i = 2, counter = 0; counter <= 10001; i++) {
		if (sosuu(i) == 0)
			counter += 1;
	}

	printf("ans: %d\n", i-1);
}

