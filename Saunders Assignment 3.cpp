/*
Spring 2018, COP2272C.04 Computer Programming 1
Assignment 3
Purpose: Write a program that defines and uses every member function in the EvenNumber class for representing an even number.

The class contains:

A data field value of the int type that represents the integer value stored in the object.
A function named getNext() to return the next value of even number after the current value in this object.
A default constructor (also known as no-arg constructor) that creates an EvenNumber object for the default value 0.
A parameterized constructor (also known as explicit constructor) that constructs an EvenNumber object with the specified value.
A function named getValue() to return an int value for this object.
A function named setValue() to change the current value for this object.

Name: Max Saunders
*/

#include <iostream>  // for standard i/o
using namespace std; //reserve library objects for standard use



#include <iostream>;
using namespace std;

class EvenNumber //Creates the even number class
{

public:

	EvenNumber()  // default constructor
	{
		num = 0;
	}
	EvenNumber(int startNum) //Parameterized constructors
	{
		num = startNum;
	}

	int getValue() const //create function to get the number
	{
		return num;
	}

	int nextValue(int passedVal)
	{
		int evenN = passedVal + 1;
		if (evenN % 2 == 0)
		{							//Returns the next even number
			return evenN;
		}
		else
		{
			return evenN + 1;
		}
	}

	void setValue(int newValue)
	{
		num = newValue;
	}

private:
	int num;
};

int main()
{
	int num1, num2;

	cout << "Enter a value: " << endl; // Ask user for first number
	cin >> num1;

	EvenNumber newNumber(num1); //Makes a new object from the EvenNumber class
	cout << "The next even number is: " << newNumber.nextValue(newNumber.getValue()) << endl; //call the class function to print the next even number
	cout << "Enter another number: " << endl; //prompt the user for the second number
	cin >> num2;

	newNumber.setValue(num2); //Changes the value of the object using the class function
	cout << "The next even Value is " << newNumber.nextValue(newNumber.getValue()) << endl; //prints the next even number

	return 0;
}