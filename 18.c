#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COL 15

void main()
{
	int x[COL][COL];
	int i, j, tmp, max, bak;
	FILE *fp;
	char c[COL*3];

	if ((fp = fopen("18.num", "r")) == NULL) {
                printf("file open error!!\n");
                exit(EXIT_FAILURE);
        }

        for(i = 0; i < COL; i++) {
                fgets(c, COL*3, fp);
                x[i][0] = atoi(strtok(c, " "));
                for(j = 1; j < i+1; j++) {
                        x[i][j] = atoi(strtok(NULL, " "));
                }
        }

/*
	for(i = 0; i < COL; i++){
		for(j = 0; j < i+1; j++)
			printf("%d, ", x[i][j]);
		printf("\n");
	}
*/
	for(i = 0; i < COL-1; i++) {
		bak = x[i+1][0];
		for(j = 0; j < i+1; j++) {
//			printf("%d, ", x[i][j]);
			tmp = x[i][j] + bak;
			if (tmp > x[i+1][j])
				x[i+1][j] = tmp;

			bak = x[i+1][j+1];
			tmp = x[i][j] + x[i+1][j+1];
			if (tmp > x[i+1][j+1])
				x[i+1][j+1] = tmp;
		}
//printf("\n");
	}

	for(max = 0, i = 0; i < COL; i++) {
		if (max < x[COL-1][i]){
			max = x[COL-1][i];
		}
	}

	printf("ans: %d\n", max);
}
