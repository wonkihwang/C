/*
Name: Wonki Hwang
Student number:143755163
Email:whwang6@myseneca.ca
Workshop:Week 5
Section:IPC144SRR
Date:Feb. 14, 2017
*/

#include <stdio.h>
#define SIZE 4

struct employee {
	int id;
	int age;
	double salary;
};

int main(void) {

	struct employee emp[SIZE] = { {0} };
	struct employee e;
	int option = 0;
	int i = 0;
	int num = 0;
	int cntID;
	int result;

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	//Exit
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1: //Display Employee Information
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				};
			}
			printf("\n");
			break;
		case 2: //Add Employee
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
			break;
		case 3: //Update Employee Salary
			result = 0;
			printf("Update Employee Salary\n");
			printf("======================\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &e.id);
				for (cntID = 0; cntID < SIZE ; cntID++) {
					if (emp[cntID].id == e.id) {
						printf("The current salary is %.2lf\n", emp[cntID].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &e.salary);
						emp[cntID].salary = e.salary;
						result = 1;
					}
				}
			} while (result != 1);
			printf("\n");
			break;
		case 4: //Remove Employee
			result = 0;
			printf("Remove Employee\n");
			printf("===============\n");
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &e.id);
				for (cntID = 0; cntID < SIZE; cntID++) {
					if (emp[cntID].id == e.id) {
						printf("Employee %d will be removed\n", emp[cntID].id);
						emp[cntID].id = 0;
						emp[cntID].age = 0;
						emp[cntID].salary = 0;
						result = 1;
					}
				}
			} while (result != 1);
			printf("\n");
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}
