#include <stdio.h>

int soinsuu(int i)
{
	int j;

	for(j = 2; j < i; j++) {
		if (i % j == 0)
			return 1;
	}
	return 0;
}

void main()
{
	int flag;
	long long int target, i, j;
	target = 600851475143;

	for(i = 2; i < target / 2;) {
		if (soinsuu(i) == 0) {
			if (target % i == 0) {
printf("i: %d\n", i);
				target /= i;
			} else{
				i++;
			}
		} else{
			i++;
		}
/*
		if (target % i == 0) {
			flag = 0;
			for(j = 2; j < i; j++) {
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
*/
	}
	printf("ans: %d, %d\n", target, i);
}
