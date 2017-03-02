/*
Name: Wonki Hwang
Student number: 143755163
Email: whwang6@myseneca.ca
Workshop: IPC-Workshop3
Section: IPC144SRR
Date: Jan 31, 2017
*/

#include <stdio.h>
#define NUMS 4

int main() {
	double high;
	double low;
	double toth = 0;
	double totl = 0;
	double avg;
	double max, min;
	int cnt;
	int maxday, minday;
	printf("---=== IPC Temperature Analyzer ===---\n");
	for (cnt = 0; cnt < NUMS; cnt++) {
		printf("Enter the high value for day %d: ", cnt + 1);
		scanf("%lf", &high);
		printf("\n");
		printf("Enter the low value for day %d: ", cnt + 1);
		scanf("%lf", &low);
		printf("\n");
		while (high < low || high > 40 || low < -40) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n"); 
			printf("Enter the high value for day %d: ", cnt + 1);
			scanf("%lf", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", cnt + 1);
			scanf("%lf", &low);
			printf("\n");
		}
		toth += high;
		totl += low;
		if (cnt == 0) {
			max = high;
			min = low;
			maxday = 1;
			minday = 1;
		}
		else {
			if (max < high) {
				max = high;
				maxday = cnt + 1;
			}
			if (min > low) {
				min = low;
				minday = cnt + 1;
			}
		}
	}
	avg = (toth + totl) / (NUMS * 2);
	printf("The average (mean) temperature was: %.2lf\n", avg);
	printf("The highest temperature was %.lf, on day %d\n", max, maxday);
	printf("The lowest temperature was %.lf, on day %d\n", min, minday);
	return 0;
}





