// Le Cai
// LZC0033
// hw4_lzc0033.cpp
// I used instructions as help
// I also used bubbleSort from algorithm class to help me sort the array.
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX_SIZE = 100;
// read how many numbers are in the file
int readfile(int inputArray[], ifstream& inStream)
{
   int index = 0;

   inStream >> inputArray[index];
   while (!inStream.eof())  {
      index++;
      inStream >> inputArray[index];
   }

   return index;
}
//swap function for bubbleSort
void swap(int *xp, int *yp)
{
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}
//bubbleSort for sorting
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
      swapped = false;
      for (j = 0; j < n-i-1; j++)
      {
         if (arr[j] > arr[j+1])
         {
            swap(&arr[j], &arr[j+1]);
            swapped = true;
         }
      }

     // IF no two elements were swapped by inner loop, then break
      if (swapped == false)
         break;
   }
}
//I combined two arrays into one array unsorted, then sort the array with bubbleSort.
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[])
{
   int outputArray_size = inputArray1_size + inputArray2_size;

   for (int i = 0; i < inputArray1_size; i++)  {
      outputArray[i] = inputArray1[i];
   }

   for (int i = inputArray1_size; i < outputArray_size; i++) {
      outputArray[i] = inputArray2[i - inputArray1_size];
   }

   bubbleSort(outputArray, outputArray_size);

   return outputArray_size;


}
//writefile to output.txt
void writefile(int outputArray[], int outputArray_size, ofstream &outStream)
{
   for (int i = 0; i < outputArray_size; i++)  {
      outStream << outputArray[i] << endl;
   }
}



int main()
{
   ifstream inStream;
   ofstream outStream;
   int data;

   int iArray1_size;
   int iArray2_size;
   int outputArray_size;

   int iArray1[MAX_SIZE];
   int iArray2[MAX_SIZE];
   int outputArray[MAX_SIZE];

   string filename;
   string targetname = "output.txt";

   cout << "*** Welcome to Le Cai's sorting program ***\n";
   // read input1.txt, output both amount and number.
   cout << "Enter the first input file name: ";
   cin >> filename;

   //inStream.open(filename);
   inStream.open((char*)filename.c_str());

   if (inStream.fail())  {
      cout << "Input file opening failed." << endl;
      exit(1);
   }

   iArray1_size = readfile(iArray1, inStream);
   iArray1_size++;
   cout << "The list of " << iArray1_size << " numbers in file " << filename << " is:\n";

   while (!inStream.eof()) {
      cout << data << endl;
      inStream >> data;
   }
   for (int i = 0; i < iArray1_size; i++) {
      cout << iArray1[i];
      cout << endl;
   }

   inStream.close();
   inStream.clear();
// read input2.txt. output both amount and number.
   cout << "\nEnter the second input file name: ";
   cin >> filename;

   //inStream.open(filename);
   inStream.open((char*)filename.c_str());

   if (inStream.fail())  {
      cout << "Input file opening failed." << endl;
      exit(1);
   }

   iArray2_size = readfile(iArray2, inStream);
   iArray2_size++;
   cout << "The list of " << iArray2_size << " numbers in file " << filename << " is:\n";

   while (!inStream.eof()) {
      cout << data << endl;
      inStream >> data;
   }
   for (int i = 0; i < iArray2_size; i++) {
      cout << iArray2[i];
      cout << endl;
   }

   inStream.close();
   inStream.clear();
// sort array1 and array2 into a output array.
   outputArray_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);
   cout << "\nThe sorted list of " << outputArray_size << " numbers is: ";
   for (int i = 0; i < outputArray_size; i++)  {
      cout << outputArray[i] << " ";
   }
   cout << endl;
// open output file and write outputArray.
   //outStream.open(targetname);
   outStream.open((char*)targetname.c_str());

   if (outStream.fail()) {
      cout << "Output file opening failed.";
      exit(1);
   }
   writefile(outputArray, outputArray_size, outStream);

   return 0;
}
