//Max Saunders 
//COP 2272C.04 
//Feng-Jen Yang
//Assignment 1- Pg 66 Excersize 2.7

#include<iostream>
using namespace std;

int main()
{
	int x;
	int y;
	int d;

	cout << "Enter the number of minutes: "<<endl;
	cin >> x;
//60x24x365=525,000
	y = (x / (525600));
	d = ((x / (1440)) - (y * 365));

	cout <<"The number of years is " << y <<" and the number of days is "<< d <<endl;

	system("pause");
	return 0;
}
