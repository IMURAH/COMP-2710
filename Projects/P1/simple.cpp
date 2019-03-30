//Le Cai Lzc0033@auburn.edu
//simple.cpp for Project 1
//Google helped me with initializing array
//Sample code standard.cpp and factorial.cpp helped me with the code as well

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int i, n, factorial = 1;

   cout << "please enter number with in 1 - 10 for factorial number: ";
   cin >> n;

   while (n < 0 || n > 10) {
      cout "please enter number with in 1 - 10 range: ";
      cin >> n;
   }

   for (i = 1; i <= n; ++i)  {
      factorial *= i;
   }
   cout << "Factorial of "<<n<<" = "<<factorial;
   cout << endl;

   float* data = NULL;
   int x;
   cout << "Enter array size: ";
   cin >> x;
   data = new float[n];

   cout << "Enter elements for array: ";
   for(i = 0; i < n; ++i)
      cin >> data[i];

   cout << endl << "standardDeviation = " << calculateSD(data);

   return 0;
}

float calculateSD(float data[])
{
   float sum = 0.0, mean, standardDeviation = 0.0;

   int i;

   for(i = 0; i < 10; ++i)
   {
      sum += data[i];
   }

   mean = sum/10;

   for(i = 0; i < 10; ++i)
      standardDeviation += pow(data[i] - mean, 2);

   return sqrt(standardDeviation / 10);
}
