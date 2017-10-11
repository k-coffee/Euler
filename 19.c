#include <stdio.h>

#define MAX 1200

void main()
{
	int month, day, year;
	int x[MAX];
	int counter = 0;
	int num = 0 ;
	int i;
	//int uruu = 0;

	year = 1901;
	month = 1;
	day = 1;

	counter = 366;

	while(year < 2001) {
//		printf("%d: %d: %d\n", year, month, day);
		if (day == 1) {
			x[num] = counter;
			num++;
		}

		if (day >= 28) {
			if (month == 2) {
				if (year % 4 == 0) {
					if (year % 400 != 0 && year % 100 == 0) {
						day = 1;
						month++;
					} else {
						if (day == 29) {
							day = 1;
							month++;
						} else {
							day++;
						}
					}
				} else {
					day = 1;
					month++;
				}
			} else if (month == 9 || month == 4 || month == 6 || month == 11) {
				if (day == 30) {
					day = 1;
					month++;
				} else
					day++;
			} else {
				if (day == 31) {
					day = 1;
					month++;
				} else
					day++;
			}
		} else {
			day++;
		}
		if (month == 13) {
			month = 1;
			year++;
		}
		counter++;
	}

	counter = 0;
	for (i = 0; i < num; i++) {
//		printf("%d, ", x[i]);
		if (x[i] % 7 == 0)
			counter++;
	}
	
	printf("ans: %d\n", counter);
}
