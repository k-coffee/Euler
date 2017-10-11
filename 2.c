#include <stdio.h>

void main(int argc, char *argv[])
{
	int i, tmp, bak, sum;

	bak = 1;
	for(i = 2; i <= 4000000;) {
		if (i % 2 == 0)
			sum +=	i;
		tmp = bak;
		bak = i;
		i = i + tmp;
	}
	printf("ans: %d\n", sum);
}
