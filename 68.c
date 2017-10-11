#include <stdio.h>

int ans[16];

int five_gon_check(int x[])
{
    if (x[0]+x[5]+x[6] == x[1]+x[6]+x[7] && x[1]+x[6]+x[7] == x[2]+x[7]+x[8] && x[2]+x[7]+x[8] == x[3]+x[8]+x[9] && x[3]+x[8]+x[9] == x[4]+x[9]+x[5])
        if (x[0] < x[1] && x[0] < x[2] && x[0] < x[3] && x[0] < x[4])
            return 1;
    return 0;
}

void make_five_gon(int five_gon[], int flags[], int c)
{
    int i, j;
    int tmp[16];

    if(c >= 10) {
        if(five_gon_check(five_gon) == 1) {
            for (i = 0; i < 16; i++)
                tmp[i] = 0;

            tmp[0] = five_gon[0];
            tmp[1] = five_gon[5];
            tmp[2] = five_gon[6];
            tmp[3] = five_gon[1];
            tmp[4] = five_gon[6];
            tmp[5] = five_gon[7];
            tmp[6] = five_gon[2];
            tmp[7] = five_gon[7];
            tmp[8] = five_gon[8];
            tmp[9] = five_gon[3];
            tmp[10] = five_gon[8];
            tmp[11] = five_gon[9];
            tmp[12] = five_gon[4];
            tmp[13] = five_gon[9];
            tmp[14] = five_gon[5];

            for (i = 14; i >= 0; i--) {
                if (tmp[i] == 9) {
                    tmp[i+1] = 0;
                    tmp[i] = 1;
                    for (j = i-1; j >= 0; j--) {
                        tmp[j] += 1;
                    }
                    break;
                } else {
                    tmp[i+1] = tmp[i] + 1;
                }
            }

            for (i = 0; i < 16; i++) {
                if (ans[i] < tmp[i]) {
                    for (j = 0; j < 16; j++)
                        ans[j] = tmp[j];
                    break;
                }
                if (ans[i] > tmp[i]) {
                    break;
                }
            }
        }
    }

    if (c < 5) {
        for (i = 0; i < 10; i++) {
            if (flags[i] == 0) {
                flags[i] = 1;
                five_gon[c] = i;
                make_five_gon(five_gon, flags, c+1);
                flags[i] = 0;
            }
        }
    } else {
        for (i = 0; i < 9; i++) {
            if (flags[i] == 0) {
                flags[i] = 1;
                five_gon[c] = i;
                make_five_gon(five_gon, flags, c+1);
                flags[i] = 0;
            }
        }
    }
}

void main()
{
    int five_gon[10];
    int flags[10];
    int i;

    for(i=0; i<10; i++)
        flags[i] = 0;

    for (i = 0; i < 17; i++)
        ans[i] = 0;

    make_five_gon(five_gon, flags, 0);

    printf("ans: ");
    for (i = 0; i < 16; i++){
        printf("%d", ans[i]);
    }
    printf("\n");
}
