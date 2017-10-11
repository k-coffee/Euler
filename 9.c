#include <stdio.h>

void main()
{
	int a, b, c;

	for (c = 1000; c > 0; c--) {
		for (b = c-1, a = 1000-b-c; b >= a; b--, a++) {
//		for (b = 1000; b > 0; b--){
//		for (a = 1000; a > 0 ; a--){
			if (((a * a + b * b) == c * c) && (a+b+c == 1000)) {
				if (a > 0) {
					printf("ans: %d\n", a*b*c);
					break;
				}
			}
//}
		}
	}
}
