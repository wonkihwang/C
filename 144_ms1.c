#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


// code your functions here:

// printing welcome messege
void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n");
}

// printing title
void printTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

// printing footer
void printFooter(double grandTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (grandTotal > 0) {
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
	}
}

// clearing keyboard when read new line
void flushKeyboard(void) {
	int badVal = 1;
	char newline = 'x';
	while (newline != '\n') {
		scanf("%c", &newline);
		if (newline != '\n') {
			newline = getchar();
		}
	}
}

// pause until hit enter
void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

// getting valid integer value
int getInt(void) {
	int Value;
	char NL = 'x';
	while (NL != '\n') {
		scanf("%d%c", &Value, &NL);
		if (NL != '\n') {
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}
	return Value;
}

// getting integer value within the limits required
int getIntLimited(int lowerLimit, int upperLimit) {
	int value;
	do {
		value = getInt();
		if (value < lowerLimit || value > upperLimit) {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		}
	} while (value < lowerLimit || value > upperLimit);
	return value;
}

// getting valid double value
double getDouble(void) {
	double Value;
	char NL = 'x';
	while (NL != '\n') {
		scanf("%lf%c", &Value, &NL);
		if (NL != '\n') {
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}
	return Value;
}

// getting double value within the limits required
double getDoubleLimited(double lowerLimit, double upperLimit) {
	double value;
	do {
		value = getDouble();
		if (value < lowerLimit || value > upperLimit) {
			printf("Invalid value, %lf < value < %lf: ", lowerLimit, upperLimit);
		}
	} while (value < lowerLimit || value > upperLimit);
	return value;
}
