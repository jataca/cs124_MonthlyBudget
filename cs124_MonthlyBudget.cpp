/***********************************************************************
* Program:
*    Project 1, Monthly Budget
*    Brother Helfrich, CS124
* Author:
*    Jacob Casperson
* Summary: 
*    This program is a simple monthly budget. It keeps track of income,
*    living expenses, taxes, tithing, and other expenses.
*
*    Estimated:  Didn't make an estimate    
*    Actual:     I have no idea! Maybe 8 hours total. 
*      The if statement in computeTax() was a pain, somethings didn't
*      work that I still believe should have worked.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This function prompts the user for and returns monthly income
 ***********************************************************************/
float getIncome()
{
   float monthlyIncome;

   // User input
   cout << "\tYour monthly income: ";
   cin >>  monthlyIncome;

   return monthlyIncome;
}
   
/**********************************************************************
 * Prompt the user and return the budgeted living expense
 ***********************************************************************/
float getBudgetedLiving()
{
   float budgetedLivingExpenses;

   cout << "\tYour budgeted living expenses: ";
   cin  >> budgetedLivingExpenses;

   return budgetedLivingExpenses;
}

/**********************************************************************
 * Prompt the user and return the actual living expense
 ***********************************************************************/
float getLivingExpenses()
{
   float actualLivingExpenses;

   cout << "\tYour actual living expenses: ";
   cin >> actualLivingExpenses;

   return actualLivingExpenses;
}

/**********************************************************************
 * Prompt the user to get and return all taxes withheld
 ***********************************************************************/
float getTaxesWithheld()
{
   float taxesWithheld;

   cout << "\tYour actual taxes withheld: ";
   cin >> taxesWithheld;

   return taxesWithheld;
}

/**********************************************************************
 * Prompt the user to get and return all tithes offered
 ***********************************************************************/
float getTitheOfferings()
{
   float titheOfferings;

   cout << "\tYour actual tithe offerings: ";
   cin >> titheOfferings;

   return titheOfferings;
}

/**********************************************************************
 * Prompt the user to get and return all other expenses
 ***********************************************************************/ 
float getOtherExpenses()
{
   float otherExpenses;

   cout << "\tYour actual other expenses: ";
   cin  >> otherExpenses;

   return otherExpenses;
}

/**********************************************************************
 * Compute and return 10% of the monthly income
 ***********************************************************************/ 
float computeTithing(float income)
{
   float expectedTithing = income / 10.00;
   
   return expectedTithing;
}

/**********************************************************************
 * Compute taxes that are due
 ***********************************************************************/ 
float computeTax(float monthlyIncome)
{
   float yearlyIncome = monthlyIncome * 12.00;
   float yearlyTax;
   float monthlyTax;

   if (yearlyIncome < 15100.00)
      yearlyTax = yearlyIncome * 0.10;
   else if (yearlyIncome < 61300.00)
      yearlyTax = 1510.00 + 0.15 * (yearlyIncome - 15100.00);
   else if (yearlyIncome < 123700.00)
      yearlyTax = 8440.00 + 0.25 * (yearlyIncome - 61300.00);
   else if (yearlyIncome < 188450.00)
      yearlyTax = 24040.00 + 0.28 * (yearlyIncome - 123700.00);
   else if (yearlyIncome < 336550.00)
      yearlyTax = 42170.00 + 0.33 * (yearlyIncome - 188450.00);
   else
      yearlyTax = 91043.00 + 0.35 * (yearlyIncome - 336550.00);
   
   monthlyTax = yearlyTax / 12.00;
   
   return monthlyTax;
}

/**********************************************************************
 * Display the table of the monthly budget. Note that there are b's in
 * front of some variable names that stand for budget and the a's stand
 * for actual. i.e bTaxes and aTaxes. 
 ***********************************************************************/ 
void display(float income, float bTaxes, float aTaxes, float bTithing, float aTithing,
             float bLiving, float aLiving, float bOther, float aOther, float difference)
{
   cout << "\nThe following is a report on your monthly expenses\n"
        << "\tItem                  Budget          Actual\n"
        << "\t=============== =============== ===============\n"
        << "\tIncome          $" << setw(11) << income   << "    $" << setw(11) << income     << "\n"
        << "\tTaxes           $" << setw(11) << bTaxes   << "    $" << setw(11) << aTaxes     << "\n"
        << "\tTithing         $" << setw(11) << bTithing << "    $" << setw(11) << aTithing   << "\n"
        << "\tLiving          $" << setw(11) << bLiving  << "    $" << setw(11) << aLiving    << "\n"
        << "\tOther           $" << setw(11) << bOther   << "    $" << setw(11) << aOther     << "\n"
        << "\t=============== =============== ===============\n"
        << "\tDifference      $" << setw(11) << 0.00     << "    $" << setw(11) << difference << "\n";
      
   return;
}

/**********************************************************************
 * Main function!!! At last you made it to the last function! First of
 * all this function sets all numbers to show two decimals and the
 * decimal point. Next it provides the introduction to the program.
 * Next it creates a whoule bunch of variables for all the numbers the
 * user enters and a couple more just to be safe! Finally it calls the
 * display() function to provide a neat table for Brother Helfrich to
 * look at. 
 ***********************************************************************/ 
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   //Introduction to the program
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
   
   //
   float monthlyIncome = getIncome();
   float budgetedLivingExpenses = getBudgetedLiving();
   float actualLivingExpenses = getLivingExpenses();
   float taxesWithheld = getTaxesWithheld();
   float titheOfferings = getTitheOfferings();
   float otherExpenses = getOtherExpenses();
   float monthlyTax = computeTax(monthlyIncome);
   float expectedTithing = computeTithing(monthlyIncome);
   float budgetedOther = monthlyIncome - (budgetedLivingExpenses + expectedTithing + monthlyTax);
   float difference = monthlyIncome - (actualLivingExpenses + titheOfferings + taxesWithheld + otherExpenses);
   
   display(monthlyIncome, monthlyTax, taxesWithheld, expectedTithing, titheOfferings,
           budgetedLivingExpenses, actualLivingExpenses, budgetedOther, otherExpenses, difference);

   return 0;
}
