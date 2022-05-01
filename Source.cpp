/*Create a class Test.
Test has 4 data members namely, dm1,dm2, dm3, dm4 of different data types.
dm1 belongs to Date class, you can choose any data type for other data members.
dm1 is a static data member and is only changed by calling a function dm1Modify().
Initial value of dm1 is set to your birthdate.
dm1Modify() always shifts the date to next date.
dm1Modify() is called every time a constructor or destructor is called for the class.
Create appropriate set and get methods for each data member.
Using the concepts studied in course, enforce the constraint on functions that are not supposed to change data members must not do so even by mistake.*/


#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int inputDay, int inputMonth, int inputYear) : day(inputDay), month(inputMonth), year(inputYear) {};
	//Function takes int and sends it for parsing to set day
	void setDay(int inputDay)
	{
		parseDays(inputDay);
	}
	//Function increments day by one and sends value for parsing to set day
	void operator++()
	{
		parseDays(day + 1);
	}
	//Function increments day by one and sends value for parsing to set day
	void operator++(int)
	{
		parseDays(day + 1);
	}
	//Returns value of day
	int getDay() const
	{
		return day;
	}
	//Function takes int and sends it for parsing to set month
	void setMonth(int inputMonth)
	{
		parseMonths(inputMonth);
	}
	//Returns value of month
	int getMonth() const
	{
		return month;
	}
	//Function takes int and sets year to it
	void setYear(int inputYear)
	{
		year = inputYear;
	}
	//Returns value of year
	int getYear() const
	{
		return year;
	}
	//Function takes int and parses it to determine if the day number is valid for the current month
	void parseDays(int inputDay)
	{
		//Month is 4, 6, 9 or 11 can not have more than 30 days. Month 2 during a leap year can not have more than 29 days.
		//Month 2 not during a leap year can not have more than 28 days. A month can not have more than 31 days.
		if ((inputDay > 30 && month == 4) || (inputDay > 30 && month == 6) || (inputDay > 30 && month == 9) || (inputDay > 30 && month == 11) ||
			(inputDay > 29 && month == 2 && year % 4 == 0) || (inputDay > 28 && month == 2 && year % 4 != 0) || (inputDay > 31))
		{
			day = 1;
			setMonth(month + 1);
		}
		else
		{
			day = inputDay;
		}
	}
	void parseMonths(int inputMonth)
	{
		//A year can not have more than 12 months
		if (inputMonth > 12)
		{
			month = 1;
			year++;
		}
		else
		{
			month = inputMonth;
		}
	}
};
class Test
{
private:
	static Date dm1;
	int dm2;
	float dm3;
	string dm4;
public:
	//Constructor calls dm1Modify(), innitializes dm2 and dm3 to 0 and sets dm4 to empty string
	Test()
	{
		dm1Modify();
		cout << "Date modified by constructor: "; printDm1();
		dm2 = 0;
		dm3 = 0;
		dm4.assign("");
	}
	//Function increments date by 1 day
	static void dm1Modify()
	{
		dm1++;
	}
	//Functions takes int and sets dm2 to it
	void setDm2(int inputDm2)
	{
		inputDm2 = dm2;
	}
	//Function returns the value of dm2
	int getDm2() const
	{
		return dm2;
	}
	//Functions takes float and sets dm2 to it
	void setDm3(float inputDm3)
	{
		inputDm3 = dm3;
	}
	//Function returns the value of dm3
	float getDm3() const
	{
		return dm3;
	}
	//Functions takes string and sets dm4 to it
	void setDm4(string inputDm4)
	{
		dm4.assign(inputDm4);
	}
	//Function returns dm4 string
	string getDm4() const
	{
		return dm4;
	}
	//Function prints dm1 date in DD/MM/YYYY format
	static void printDm1() 
	{
		cout << setfill('0') << setw(2) << dm1.getDay() << "-" << setw(2) << dm1.getMonth() << "-" << setw(4) << dm1.getYear() << endl << endl;;
	}
	//Function prints dm1 date in DD/MM/YYYY format, dm2, dm3 and dm4
	void print() const
	{
		printDm1();
		cout << "dm2: " << dm2 << endl;
		cout << "dm3: " << dm3 << endl;
		cout << "dm4: " << dm4 << endl;
	}
	//Destructor calls dm1Modify() and calls printDm1;
	~Test()
	{
		dm1Modify();
		cout << "Date modified by destructor: "; printDm1();

		cout << endl << endl << "Assignment prepared by: " << endl;
		cout << "Daniel Sarfraz: 01-134212-035" << endl;
		cout << "Mughees Tariq: 01-134212-093" << endl;
	}
};
//Initalizes static data member dm1 in Test class
Date Test::dm1(4, 11, 2001);

int main()
{
	cout << "Actual date of birth is: "; Test::printDm1();
	Test obj;
	
	obj.dm1Modify();
	cout << "Date modified by dm1Modify() : "; obj.printDm1();
	

	_getch();
	return 0;
}
