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
typedef struct _rental
{
	int id;						// ID of the Rental Vehicle
	double baseDay;				// Daily Base Price 
	double earnings;			// Total earnings from this rental
} Rental;


double addPositive(double amount, double newAmount);

double taxCalc(double price, double rate);

double subtractPositive(double amount, double newAmount);


/* main program */
int main()
{
   const int noVehicles = 3;			// Number of Vehicles [ Changed to 3]
   int option;							// Variable to store the option selected
   int flag;							// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0;							// Variable for "for-loop" counters
   int numDay = 0;
   int numKilo = 0;
   int gcAmount;
   double price = 0;
   double kiloCost = 0;
   double charge = 0;
   double taxes = 0;
   char yn;

   Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{ 125, 29.95, 0 } };

   double taxRate = 14;				// Tax rate is 14%
   double discount = 5;    			// Discount amount for rentals (in CAD)

    /*Declare Your Variables Here*/


   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      // Display the option list
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("3.) Apply Taxes to All Rentals\n");
      printf("4.) Apply Gift Card\n");
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

         // Finding the correct vehicle index
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

			 // Apply Discount with a prompt for Y or N
			 // If the user input is skipped without being prompted, have one space infront 
			 // of %c in the scanf statement => " %c" instead of "%c"
			 printf("Apply Discount: ");
			 scanf(" %c", &yn);
			 
			 /* If the input is 'Y' or 'y' then call function subtractPositive with current earnings
			 for the rental and discount (5 CAD) as arguments and assign the returned
			 result back to earnings
			 */
			 if (yn == 'y' || yn == 'Y') {
				 vRent[flag].earnings = subtractPositive(vRent[flag].earnings, discount);
				 yn = 'Y';
			 }
			 else if (yn == 'n' || yn == 'N') {
				 yn = 'N';
			 }

			 // Display Base Charge, cost for km and the Total 
			 printf("\nBase   kmCost DiscStatus Total\n");
			 printf("====== ====== ========== ======\n");
			 printf("%6.2lf %6.2lf %10c %6.2lf\n", price, kiloCost, yn, vRent[flag].earnings);
			 printf("\n");
			 // Use "%6.2lf %6.2lf %10c %6.2lf" formatting inside a printf statement
		 }
		 else {
			 printf("ERROR: Vehicle ID does not exist.\n\n");
		 }

         break;

      case 3: // Apply Taxes to all Earnings

         printf("\n-- Apply Taxes To all Accounts--\n\n");

         printf("ID#      Earnings   Taxes\n");
         printf("-------- ---------- ------\n");
		 for (i = 0; i < noVehicles; i++) {
			 taxes = taxCalc(vRent[i].earnings, taxRate);
			 vRent[i].earnings = addPositive(vRent[i].earnings, taxes);
			 printf("%8d %10.2lf %6.2lf\n", vRent[i].id, vRent[i].earnings, taxes);
		 }
		 printf("\n");
         // Iterate over all Rentals. For each rental, calculate the taxes by calling taxCalc 
         // by passing current earnings and tax rate
         // Then call addPositive with current earnings and the taxes returned from taxCalc function
         // Then use "%8d %10.2lf %6.2lf" formatting to display ID, Earnings and taxes for each rental

         break;

      case 4: // Apply Gift Card

         flag = -1;
         printf("\n-- Apply Gift Card --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);


         // Finding the correct vehicle index
         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }
         if (flag != -1) {

            // Capture Gift card amount
			 printf("Enter Gift Card Amount: ");
			 scanf("%d", &gcAmount);
            /* call function subtractPositive with current earnings for the rental and Gift card
            amount as arguments and assign the returned result back to earnings
            */
			 vRent[flag].earnings = subtractPositive(vRent[flag].earnings, gcAmount);
			 printf("Discount Applied\n");
         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         printf("\n");

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

double taxCalc(double price, double rate) {
	double taxes;
	taxes = price * (rate / 100);
	return taxes;
}

double subtractPositive(double amount, double newAmount) {
	double amt;
	if (newAmount > 0) {
		amt = amount - newAmount;
	}
	else {
		amt = amount;
	}
	return amt;
}
