#include <stdint.h>
#include <stdio.h>
#include <limits.h>

int main(void) {
	double x = 7.0;
	int integer = (int)x;
	double remain = x - integer;

	printf("Remain = %lf\n", remain);

	int leading_zeroes = -1;

	while(remain < 1.0) {
		leading_zeroes++;
		remain *= 10;
	}

	printf("Leading zeroes = %d\n", leading_zeroes);
	printf("Remain = %lf\n", remain);

	while((long)remain * 10 < INT_MAX)
		remain *= 10;

	printf("Remain = %ld (max %d)\n", (long)remain, INT_MAX);
	
	while(!((long)remain % 10))
		remain /= 10.;

	printf("Remain = %ld\n", (long)remain);

	int fract = (int)remain;

	while (leading_zeroes--)
		putchar('0');
	printf("%d\n", fract);

	return 0;
}
