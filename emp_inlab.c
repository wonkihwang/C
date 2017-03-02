/*
Name: Wonki Hwang
Student number:143755163
Email:whwang6@myseneca.ca
Workshop:Week 5
Section:IPC144SRR
Date:Feb. 14, 2017
*/

#include <stdio.h>
#define SIZE 2

struct employee {
	int id;
	int age;
	double salary;
};

int main(void) {

	struct employee emp[SIZE] = { {0} };
	int option = 0;
	int i = 0;
	int num = 0;
	
	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		// Capture input to option variable
		scanf("%d",&option);
		printf("\n");
		
		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				};
			}
			printf("\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 
			
			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

			break;
		case 2:	// Adding Employee
				// @IN-LAB
			
			printf("Adding Employee\n");
			printf("===============\n");
			if (num != SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[num].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[num].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[num].salary);
				num++; 
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			printf("\n");

			// Check for limits on the array and add employee 
			// data accordingly. 



			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0; 
}
