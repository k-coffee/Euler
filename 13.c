#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fp;
    int s[52];
    int nums[100][50];
    int i, j;
    int up, counter, hoge;
    char tmp;

    if ((fp = fopen("13.num", "r")) == NULL) {
        printf("file open error!!\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 100; i++) {
        for(j = 0; j < 50; j++) {
            tmp = getc(fp);
            nums[i][j] = atoi(&tmp);
        }
        tmp = getc(fp);
    }


    up = 0;
    hoge = 0;
    for(i = 49; i>=0; i--) {
        counter = 0;
        for(j = 99; j>=0; j--) {
            counter += nums[j][i];
        }
        counter += up;
        up = counter / 10;
        s[hoge] = counter % 10;
        hoge++;
    }
    s[hoge] = up % 10;
    hoge++;
    //s[hoge] = up % 100;
    s[hoge] = up / 10;

    /*
    for(i = hoge; i > hoge-10; i--) {
        printf("%d", s[i]);
    }
    */
    printf("%d\n", hoge);
    printf("%d\n", up);
    for(i = hoge; i > hoge-10; i--)
        printf("%d", s[i]);
}
