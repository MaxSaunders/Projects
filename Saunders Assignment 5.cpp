/*
Max Saunders
SP 2018_COP2272C.04
Assignement 5
Purpose: Please complete the following partially given program in which the ExtTime class inherits the Time class.
*/


#include <iostream>
#include <string>
using namespace std;

//declare the data type of time zone
enum TimeZone { EST, CST, MST, PST };


//declare the super class
class Time
{
public:
	Time(); //default constructor which initializes a time to 00:00:00
	Time(int, int, int); //explicit constructor which initializes a time to given hr:min:sec
	void set(int, int, int); //change a time
	void write() const; //write a time in the hh:mm:ss format
private:
	int hr; //hour
	int min; //minute
	int sec; //second
};



//Implement super class member functions here
//Defeault Constructor
Time::Time()
{
	hr = 00;
	min = 00;
	sec = 00;
}

//Explicit Constructor
Time::Time(int initHH, int initMM, int initSS)
{
	hr = initHH;
	min = initMM;
	sec = initSS;
}

//Change Time
void Time::set(int newHH, int newMM, int newSS)
{
	hr = newHH;
	min = newMM;
	sec = newSS;
}

//Print Time
void Time::write() const
{
	if (hr < 10)
		cout << "0" << hr << ":";
	else
		cout << hr << ":";
	if (min < 10)
		cout << "0" << min << ":";
	else
		cout << min << ":";
	if (sec < 10)
		cout << "0" << sec << " ";
	else
		cout << sec << " ";
}


//declare the subclass
class ExtTime : public Time
{
public:
	ExtTime(); //default constructor which initializes an extended time to 00:00:00 EST
	ExtTime(int, int, int, TimeZone); //explicit constructor which initializes an extended time to given hr:min:sec zone
	void set(int, int, int, TimeZone); //change an extended time
	void write() const; //write an extended time
private:
	TimeZone zone; //time zone
};


// Implement subclass member functions here

//Call default constructor 
ExtTime::ExtTime()
{
	zone = EST;
}

//Call explicit constructor
ExtTime::ExtTime(int initHH, int initMM, int initSS, TimeZone initzone)
	: Time(initHH, initMM, initSS)
{
	zone = initzone;
}

//Call change time function
void ExtTime::set(int newHH, int newMM, int newSS, TimeZone newzone)
{
	Time::set(newHH, newMM, newSS);
	//change timezone
	zone = newzone;
}

//Call write function
void ExtTime::write() const
{
	Time::write();
	
	//print timezone
	switch (zone)
	{
	case 0:
		cout << "EST \n";
		break;

	case 1:
		cout << "CST \n";
		break;

	case 2:
		cout << "MST \n";
		break;

	case 3:
		cout << "PST \n";
		break;

	}
}


int main()
{
	ExtTime time1, //call default constructor
		time2(10, 26, 38, CST); //call explicit constructor

								//write time1 and time2
	time1.write(); //write 00:00:00 EST
	cout << endl;
	time2.write(); //write 10:26:38 CST
	cout << endl;

	//change time1
	time1.set(6, 28, 8, PST);

	//white time1 again
	time1.write(); //write 06:28:08 PST
	cout << endl;

	return 0; //successfully done
}