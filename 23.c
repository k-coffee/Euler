#include <stdio.h>

int yakusuu(int x)
{
	int i;
        int counter = 0;
        for (i = 1; i < x; i++)
                if (x % i == 0)
                        counter += i;

        return counter;
}

void main()
{
	int i, j, tmp, counter;
	long int sum;
	int x[7000];
	int y[28123];

	counter = 0;
	sum = 0;

	for(i = 0; i < 28123; i++) {
		y[i] = -1;
	}

	for(i = 1; i <= 28123; i++) {
		if (i < yakusuu(i)) {
			x[counter] = i;
			counter++;
		}
	}

	for(i = 0; i < counter; i++)
		for(j = 0; j < counter; j++)
			if ((x[i] + x[j]) < 28123)
				y[x[i] + x[j]] = 1;

	counter = 0;
	for(i = 0; i < 28123; i++)
		if (y[i] != 1)
			sum += i;

	printf("ans: %d\n", sum);
}
