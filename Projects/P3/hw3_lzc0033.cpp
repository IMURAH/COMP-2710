// Le Cai
// LZC0033
// hw3_lzc0033.cpp
// No help is used other than materials on the prompt.
// The main function is at bottom of the code.

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

const int ECX = 10000;
const int A_PRECISION = 33;
const int B_PERCISION = 50;
bool A_alive = true;
bool B_alive = true;
bool C_alive = true;
int A_win, B_win, C_win;



// Functions
// Function No.1
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive)
{
   int sum = 0;

   if (A_alive == true)
   {
      sum++;
   }

   if (B_alive == true)
   {
      sum++;
   }

   if (C_alive == true)
   {
      sum++;
   }

   if (sum >= 2)
   {
      return true;
   }
   else {
      return false;
   }
}

//Function No.2 (Strat 1)
//Shoots Charlie 1st then Bob.
void Aaron_shoots1(bool& B_alive, bool& C_alive)
{

   int shoot_result = rand()%100;

   if (shoot_result <= A_PRECISION) {
      if (C_alive)  {
         C_alive = false;
      }
      else {
         B_alive = false;
      }
   }
}

//Function No.3
//Bob shoots Charlie then Aaron.
void Bob_shoots(bool& A_alive, bool& C_alive)
{

   int shoot_result = rand()%100;

   if (shoot_result <= B_PERCISION) {
      if (C_alive) {
         C_alive = false;
      }
      else  {
         A_alive = false;
      }
   }
}

//Function No.4
//Charlie shoots Bob then Aaron.
void Charlie_shoots(bool& A_alive, bool& B_alive)
{
   if (B_alive)  {
      B_alive = false;
   }
   else {
      A_alive = false;
   }
}

//Function No.5 (Strat 2)
//Misses if both alive, shoots whoever is left.
void Aaron_shoots2(bool& B_alive, bool& C_alive)
{
   if (B_alive && C_alive) {
      return;
   }
   else {

      int shoot_result = rand()%100;
      if (shoot_result <= A_PRECISION) {
         if (C_alive)  {
            C_alive = false;
         }
         else {
            B_alive = false;
         }
      }
   }
}

//Test Function
void test_at_least_two_alive(void)  {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";

   cout << "   Case 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "   Case passed...\n";

   cout << "   Case 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "   Case passed...\n";

   cout << "   Case 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "   Case passed...\n";

   cout << "   Case 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "   Case passed...\n";

   cout << "   Case 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "   Case passed...\n";

   cout << "   Case 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "   Case passed...\n";

   cout << "   Case 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "   Case passed...\n";

   cout << "   Case 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "Case passed...\n";
}

int main()
{
   srand(time(0));

   cout << "***Welcome to the Duel Simulator***\n";
   test_at_least_two_alive();
   cout << "Press Enter to continue...";
   cin.get();

// STRAT 1

   cout << "Ready to test strategy 1 (run " << ECX << " times): " << endl;
   cout << "Press Enter to continue...";
   cin.get();
   //Reset win counter
   A_win = 0;
   B_win = 0;
   C_win = 0;
   //loop for the simulation
   for (int i = 0; i < ECX; i++) {
     //reset alive marker
      A_alive = true;
      B_alive = true;
      C_alive = true;
      //while theres at least 2 standing this will keep looping.
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive)  {
            Aaron_shoots1(B_alive, C_alive);
         }
         if (B_alive)  {
            Bob_shoots (A_alive, C_alive);
         }
         if (C_alive)  {
            Charlie_shoots(A_alive, B_alive);
         }
      }
      //determine the winner.
      if (A_alive)  {
         A_win++;
      }
      else if (B_alive) {
         B_win++;
      }
      else  {
         C_win++;
      }
   }
   //calculate percentage
   double a1_percentage = ((double) (A_win) / ECX) * 100;
   double b1_percentage = ((double) (B_win) / ECX) * 100;
   double c1_percentage = ((double) (C_win) / ECX) * 100;
   //print result
   cout << "Aaron won " << A_win << "/" << ECX << " duels or " << a1_percentage << "%" << endl;
   cout << "Bob won " << B_win << "/" << ECX << " duels or " << b1_percentage << "%" << endl;
   cout << "Charlie won " << C_win << "/" << ECX << " duels or " << c1_percentage << "%" << endl;

// STRAT 2

   cout << endl;
   cout << "Ready to test strategy 2 (run " << ECX << " times): " << endl;
   cout << "Press Enter to continue...";
   cin.get();
   //reset win counter
   A_win = 0;
   B_win = 0;
   C_win = 0;
   //loop for simulation
   for (int i = 0; i < ECX; i++) {
      A_alive = true;
      B_alive = true;
      C_alive = true;
      //while there are two or more standing they will keep going.
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive)  {
            Aaron_shoots2(B_alive, C_alive);
         }
         if (B_alive)  {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive)  {
            Charlie_shoots(A_alive, B_alive);
         }
      }
      //determine winner
      if (A_alive)  {
         A_win++;
      }
      else if (B_alive) {
         B_win++;
      }
      else  {
         C_win++;
      }
   }
   //calculate percentage
   double a2_percentage = ((double) (A_win) / ECX) * 100;
   double b2_percentage = ((double) (B_win) / ECX) * 100;
   double c2_percentage = ((double) (C_win) / ECX) * 100;
   //print result
   cout << "Aaron won " << A_win << "/" << ECX << " duels or " << a2_percentage << "%" << endl;
   cout << "Bob won " << B_win << "/" << ECX << " duels or " << b2_percentage << "%" << endl;
   cout << "Charlie won " << C_win << "/" << ECX << " duels or " << c2_percentage << "%" << endl;

   if (a1_percentage < a2_percentage) {
      cout << "\nStrategy 2 is better than strategy 1.\n";
   }
   else {
      cout << "Strategy 1 is better than strategy 2.\n";
   }
   return 0;
}
