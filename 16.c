#include <stdio.h>

void main()
{
    int x[500];
    int i, j, up, tmp;

    for(i = 0; i < 500; i++)
        x[i] = -1;
    x[0] = 1;
    up = 0;
    for(i = 1; i <= 1000; i++) {
        up = 0;
        for(j = 0; (x[j] != -1 && j < 500); j++) {
            tmp = x[j];
            tmp *= 2;
            tmp += up;
            x[j] = tmp % 10;
            up = tmp / 10;
        }
        if (up != 0)
            x[j] = up;
    }

    tmp = 0;
    for(i = 0; (i < 500 && x[i] != -1); i++) {
        if (x[i] >= 0){
            tmp += x[i];
        }
    }
    printf("ans: %d\n", tmp);
}
