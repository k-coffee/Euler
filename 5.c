#include <stdio.h>

void main()
{
	int i, j, flag;

	for(i = 2520; ; i++) {
		flag = 0;
		for(j = 2; j <= 20; j++) {
			if(i % j != 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	printf("ans: %d\n", i);
}
