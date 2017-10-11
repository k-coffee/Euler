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
	int counter, i, tmp;

	counter = 0;
	for(i = 1; i <= 10000; i++) {
		tmp = yakusuu(i);
		if (yakusuu(tmp) == i)
			if (i != tmp)
				counter += i;
	}
	printf("ans: %d\n", counter);
}
