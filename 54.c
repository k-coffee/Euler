#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp;
	char x[50];
	char *a;
	char *b[10];
	int i, j;

	if ((fp = fopen("54.txt", "r")) == NULL) {
		printf("file open error\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 1000; i++) {
		fgets(x, 3*10+1, fp);
		//a = strtok(x, " ");
		b[0] = strtok(x, " ");
		for (j = 1; j < 10; j++) {
			b[j] = strtok(NULL, " ");
		}
		//printf("%d: %s\n", i, strtok(x, " "));
		//printf("%d: %s\n", i, a);
		for (j = 0; j < 10; j++) {
			printf("%d: %s\n", i, b[j]);
		}
	}
}
