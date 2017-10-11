#include <stdio.h>
#include <math.h>

void main()
{
	int flag;
	long long int target, i, j;
	target = 600851475143;

	for(i = (int)sqrt(target); i > 0; i--) {
		if (target % i == 0) {
			flag = 0;
			for(j = 2; j < (int)sqrt(i); j++) {
				if (i % j == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				printf("ans: %d \n", i);
				break;
			}
		}
	}
}
