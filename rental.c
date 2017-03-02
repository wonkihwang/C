/*
== Vehicle Rentals ==
Name: Wonki Hwang
Email: whwang6@myseneca.ca
Student#: 143755163
*/

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

// Structure Declaration for Vehicle Rentals
struct Rental
{
   int id;						// ID of the Rental Vehicle
   double baseDay;				// Daily Base Price 
   double earnings;			// Total earnings from this rental
};

double addPositive(double amount, double newAmount);

int main()
{
   const int noVehicles = 2;			// Number of Vehicles
   int option;							// Variable to store the option selected
   int flag;							// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0;							// Variable for "for-loop" counters
   int numDay = 0;
   int numKilo = 0;
   double price = 0;
   double kiloCost = 0;
   double charge = 0;

   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };
   
   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("0.) Log out\n\n");
      printf("Please enter an option to continue: ");

      scanf("%d", &option);

      switch (option)
      {
      case 0: // Exit the program
         break;

      case 1: // Rental Vehicle Status

         printf("\n-- Rental Vehicle Status --\n\n");
         printf("ID#      Earnings\n");
         printf("-------- ----------\n");
		 for (i = 0; i < noVehicles; i++) {
			 printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);
		 }
		 printf("\n");
         break;

      case 2: // Calculate Rental Charges

         flag = -1;
         printf("\n-- Rental Charges --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);

		 for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }

         if (flag != -1) {
			 printf("Enter Rental Period (in Days): ");
			 scanf("%d", &numDay);
			 price = vRent[flag].baseDay * numDay;

			 printf("Enter kilometers driven: ");
			 scanf("%d", &numKilo);
			 if (numKilo > 0 && numKilo <= 100) {
				 kiloCost = numKilo * distRate1;
			 }
			 else if (numKilo > 100) {
				 kiloCost = (100 * distRate1) + ((numKilo - 100) * distRate2);
			 }
			 else {
				 printf("ERROR: Entered kilometers does not valid.\n\n");
			 }
			 charge = price + kiloCost;

            /* Call addPositive function with current earnings for the rental and
               charge(calculated above) as arguments and assign the returned
               result back to earnings
            */
			 vRent[flag].earnings = addPositive(vRent[flag].earnings, charge);

            printf("\nBase   kmCost Total\n");
            printf("====== ====== ======\n");
			printf("%6.2lf %6.2lf %6.2lf\n", price, kiloCost, vRent[flag].earnings);
			printf("\n");
         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         break;


      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }


   } while (option != 0);


   return 0;
}

double addPositive(double amount, double newAmount) {
	double amt;
	if (newAmount > 0) {
		amt = amount + newAmount;
	}
	else {
		amt = amount;
	}
	return amt;
}

