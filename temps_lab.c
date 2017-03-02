/*
Name: Wonki Hwang
Student number: 143755163
Email: whwang6@myseneca.ca
Workshop: IPC-Workshop3
Section: IPC144SRR
Date: Jan 31, 2017
*/

#include <stdio.h>
#define NUMS 3

int main() {
	double high;
	double low;
	double toth = 0;
	double totl = 0;
	double avg;
	int cnt;
	printf("---=== IPC Temperature Analyzer ===---\n");
	printf("\n");
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
	}
	avg = (toth + totl) / (NUMS * 2);
	printf("The average (mean) temperature was: %.2lf\n", avg);
	return 0;
}





