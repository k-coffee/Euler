#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp;
	char x;
	int line;
	long int sum;

/*
	x = 'A';
	printf("%d\n", x);
	x = 'B';
	printf("%d\n", x);
	x = 'a';
	printf("%d\n", x);
*/

	if ((fp = fopen("22.num2", "r")) == NULL) {
		printf("file open error\n");
		exit(EXIT_FAILURE);
	}

	sum = 0;
	line = 1;
	while((x = getc(fp)) != EOF) {
//		if (x != ',' && x != '"') {
		if (x >= 'A' && x <= 'Z') {
			sum += line * (x - 64);
//printf("%c,", x);
		} else {
			line++;
		}
	}
	printf("ans: %d\n", sum);
}
