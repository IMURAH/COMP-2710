// Le Cai
// LZC0033
// hw2_lzc0033.cpp
// I used google to help me with percision.
// The format looks good under jGrasp version 2.0.5_04, however looks funky under tux server w/ powershell.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   double monthlyPayments;
   double loanAmount;
   double interestRate;

   cout << "Loan Amount: ";
   cin >> loanAmount;

   cout << "Interest Rate (% per year): ";
   cin >> interestRate;

   cout << "Monthly Payments: ";
   cin >> monthlyPayments;

   // start outputting table
   cout << "******************************************************\n";
   cout << "       Amortization Table\n";
   cout << "******************************************************\n";
   cout << "Month Balance  Payment  Rate  Interest Principal\n";
   cout << fixed << setprecision(2) << "0\t\t$" << loanAmount << " N/A\t   N/A\tN/A\t\tN/A\n";

   //calculate some elements needed in table
   double rate = interestRate / 12;
   double interestNum;
   double princleNum;
   int monthNum = 0;
   double totalInterest;

   // using a while loop instead of a for loop allows us to make sure it goes to the second to last month.
   while (loanAmount > monthlyPayments) {
      monthNum++;
      interestNum = loanAmount * (rate / 100);
      princleNum = monthlyPayments - interestNum;
      loanAmount -= princleNum;
      totalInterest += interestNum;
      if (princleNum < 0) {
         cout << "Payment is smaller than interest, Exiting...\n";
         exit(10);
      }
      cout << fixed << setprecision(2) << monthNum << "\t\t$" << loanAmount << "\t$" << monthlyPayments << "\t" << rate << "\t$" << interestNum << " \t$" << princleNum << "\n";
   }

   //printing last months info.
   interestNum = loanAmount * (rate / 100);
   monthlyPayments = loanAmount + interestNum;
   princleNum = monthlyPayments - interestNum;
   totalInterest += interestNum;
   loanAmount = 0;
   monthNum++;
   cout << fixed << setprecision(2) << monthNum << "\t\t$" << loanAmount << "\t\t$" << monthlyPayments << "\t" << rate << "\t$" << interestNum << " \t$" << princleNum << "\n";
   cout << "******************************************************\n";
   cout << endl;
   cout << "It takes " << monthNum << " months to pay off the loan.\n";
   cout << "Total interest paid is: $" << totalInterest;
   cout << endl;

   return 0;
}
