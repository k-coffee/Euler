#include <stdio.h>
#include <stdlib.h>

int char_sort(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

void main()
{
	FILE *fp;
	size_t x_size;
	char x[10000][20], c;
	int i, j, k, line;
	long int sum;

	if ((fp = fopen("22.num", "r")) == NULL) {
		printf("file open error\n");
		exit(EXIT_FAILURE);
	}

	sum = 0;
	i = 0;
	j = 0;
	while((c = getc(fp)) != EOF) {
		if (c >= 'A' && c <= 'Z') {
			x[i][j] = c;
			j++;
		} else {
			if (c == ',')
				i++;
			j = 0;
		}
	}

	x_size = i+1;

	qsort((void *)x, x_size, sizeof(x[0]), char_sort);

	for(k = 0; k <= i; k++) {
		for(j = 0; x[k][j] >= 'A' && x[k][j] <= 'Z'; j++) {
			sum += (k+1) * (x[k][j] - 64);
		}
	}

	printf("ans: %d\n", sum);
}
