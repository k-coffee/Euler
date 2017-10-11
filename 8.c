#include <stdio.h>
#include <stdlib.h>

void swap(int *nums, int c)
{
	int i;
	for(i = 1; i < 5; i++)
		nums[i-1] = nums[i];

	nums[4] = c;
}

void main()
{
	FILE *fp;
	int max, nums[5], tmp;
	char c;

	if ((fp = fopen("8.num", "r")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	c = getc(fp);
	nums[0] = atoi(&c);
	c = getc(fp);
	nums[1] = atoi(&c);
	c = getc(fp);
	nums[2] = atoi(&c);
	c = getc(fp);
	nums[3] = atoi(&c);
	c = getc(fp);
	nums[4] = atoi(&c);

/*
printf("%d, %d, %d, %d, %d\n", nums[0], nums[1], nums[2], nums[3], nums[4]);
	swap(nums, 99);
printf("%d, %d, %d, %d, %d\n", nums[0], nums[1], nums[2], nums[3], nums[4]);
*/

	max = nums[0] * nums[1] * nums[2] * nums[3] * nums[4];
	while ((c = getc(fp)) != EOF) {
		swap(nums, atoi(&c));
		tmp = nums[0] * nums[1] * nums[2] * nums[3] * nums[4];
		if (max < (nums[0] * nums[1] * nums[2] * nums[3] * nums[4]))
			max = (nums[0] * nums[1] * nums[2] * nums[3] * nums[4]);
	}
	printf("ans: %d\n", max);
}
