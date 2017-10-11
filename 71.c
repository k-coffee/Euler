#include <stdio.h>

int hcf(int n, int d)
{
    if(n == 0)
        return d;
    return hcf((d % n), n);
}

void main()
{
//    printf("%d\n", hcf(1029, 1071));
    float target = 3 / 7.0;
    float left = 0;
    float tmp;
    int i, j, ans;

    for(i = 2; i <= 1000000; i++)
    {
        printf("%d\n", i);
        tmp = 0;
//        for(j = 2 * i / 7; tmp < target; j++)
        for(j = ans; tmp < target; j++)
        {
            tmp = (j + 1) / (float)i;
            if(hcf(j, i) == 1)
//                if(j / (float)i < target)
                    if(j / (float)i > left)
                    {
                        ans = j;
                        left = j / (float)i;
                    }
        }
    }

    printf("%d: %f\n", ans, left);
}
