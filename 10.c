#include <stdio.h>
#include <math.h>

int sosuu(long int x)
{
        long int tmp;
        for(tmp = 2; tmp <= (int)sqrt(x); tmp++) {
                if (x % tmp == 0)
                        return 1;
        }
        return 0;
}

void main()
{
/*
    int i=2, j, flg, num;
    double ans=0;

    num = 0;
    while(i <= 2000000){
        flg=0;

        for(j=2; j<=(int)sqrt(i); j++){
            if(i%j == 0){
                flg = 1;
                break; 
            }
        }

        if(flg==0){
	    num += 1;
            ans += i;
        }

        i++;
    }

    printf("%.lf, %d\n", ans, num);

*/
	long int i, j;
	double sum;
        int num=0;

	for (sum=2, i=3; i <= 2000000; i++) {
//	for (sum=2, i=3; i < 10; i+=2) {
		if (sosuu(i) == 0) {
	//printf("%d\n", i);
			sum += i;
                        num += 1;
		}
	}
	printf("ans: %.lf\n", sum);
	printf("num: %d\n", num);
}
