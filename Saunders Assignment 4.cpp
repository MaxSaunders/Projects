/*
Spring 2018, COP2272C.04 Computer Programming 1
Assignment 2
Purpose:
1. creating an empty integer vector
2. filling in at least 10 randomly generated integers between 1 and 100
3. displaying the elements within the vector
4. counting how many elements within the vector can be evenly divided by 3
Name: Max Saunders
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> intVector; //Creates the vector
	int total = 0; //Creates the integer total

	//Fills the vector with random variables
	for (int i = 0; i < 10; i++)
	{
		intVector.push_back(rand() % 100 + 1);
	}

	//Prints the variables in the vector
	cout << "The random numbers generated are: " << endl;
	for (int m = 0; m < 10; m++)
	{
		cout << intVector[m] << endl;
	}
	cout << "The number of elements divisible by 3 is: ";

	//Determines the number of printed numbers evenly divisble by 3
	for (int f = 0; f < 10; f++)
	{
		if (intVector[f] % 3 == 0)
		{
			total++;
		}
	}

	//Prints total
	cout << total << endl;
	return 0;
}