#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int i, j, k, tmp;
	double max;
	FILE *fp;
	char s[20][100];
	int nums[20][20];

	if ((fp = fopen("11.num", "r")) == NULL) {
                printf("file open error!!\n");
                exit(EXIT_FAILURE);
        }

	for(i = 0; i < 20; i++) {
		fgets(s[i], 61, fp);
		nums[i][0] = atoi(strtok(s[i], " "));
		for(j = 1; j < 20; j++) {
			nums[i][j] = atoi(strtok(NULL, " "));
		}
	}

/*
	for(i = 0; i < 20; i++)
		for (j = 0; j < 20; j++) {
			if (j == 19)
			printf("%d\n", nums[i][j]);
			else
			printf("%d, ", nums[i][j]);
		}
*/

	max = 0;
// yoko
	for(i = 0; i < 20; i++) {
		for(j = 0; j <= 16; j++) {
			tmp = 1;
			for(k = j; k < j+4; k++) {
				tmp *= nums[i][k];
			}
			if (max < tmp){
				max = tmp;
				printf("yoko: %d, %d\n", i, j);
			}
		}
	}

// naname migishita
	for(i = 0; i <= 16; i++) {
		for(j = 0; j <= 16; j++) {
			tmp = 1;
			for(k = 0; k < 4; k++) {
				tmp *= nums[i+k][j+k];
			}
			if (max < tmp) {
				max = tmp;
				printf("naname migishita: %d, %d\n", i, j);
			}
		}
	}

// naname hidarishita
	for(i = 0; i <= 16; i++) {
		for(j = 3; j < 20; j++) {
			tmp = 1;
			for(k = 0; k < 4; k++) {
				tmp *= nums[i+k][j-k];
			}
			if (max < tmp) {
				max = tmp;
				printf("naname hidarishita: %d, %d\n", i, j);
			}
		}
	}

// tate
	for(i = 0; i <= 16; i++) {
		for(j = 0; j < 20; j++) {
			tmp = 1;
			for(k = i; k < i+4; k++) {
				tmp *= nums[k][j];
			}
			if (max < tmp) {
				max = tmp;
				printf("tate: %d, %d\n", i, j);
			}
		}
	}

	printf("ans: %.lf\n", max);
}
