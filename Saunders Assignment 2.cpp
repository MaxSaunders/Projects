/*
Spring 2018, COP2272C.04 Computer Programming 1
Assignment 2
Purpose:
Name: Max Saunders
*/

#include <iostream>
using namespace std;

int main()
{
	int n, row, col;

	cout << "Please enter pattern number between 1 and 9: ";
	cin >> n; //user input
	for (row = 1; row <= n; row++)
	{
		for (col = n; col >= 1; col--)
		{
			if (col <= row)
			{
				cout << col << " ";
			}
			else
				cout << " " << " ";
		}
		cout << " " << endl;
	}

	system("pause");

}