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
#include <string>

using namespace std;

class date
{
private:
	int day;
	int month;
	int year;

public:
	date(int inputDay, int inputMonth, int inputYear) : day(inputDay), month(inputMonth), year(inputYear) {};

	void setDay(int inputDay)
	{
		parseDays(inputDay);
	}

	void operator++()
	{
		parseDays(day + 1);
	}

	void operator++(int)
	{
		parseDays(day + 1);
	}

	int getDay() const
	{
		return day;
	}

	void setMonth(int inputMonth)
	{
		parseMonths(inputMonth);
	}

	int getMonth() const
	{
		return month;
	}

	void setYear(int inputYear)
	{
		year = inputYear;
	}

	int getYear() const
	{
		return year;
	}

	void parseDays(int inputDay)
	{
		if ((inputDay > 30 && month == 4) || (inputDay > 30 && month == 6) || (inputDay > 30 && month == 9) || (inputDay > 30 && month == 11) || 
			(inputDay > 28 && month == 2 && year % 4 == 0) || (inputDay > 29 && month == 2 && year % 4 != 0) || (inputDay > 31))
		{
			day = 1;
			setMonth(month + 1);
		}
		else
		{
			day++;
		}
	}

	void parseMonths(int inputMonth)
	{
		if (inputMonth > 12)
		{
			month = 1;
			year++;
		}
		else
		{
			month++;
		}
	}
};

class Test
{
private:
	static date dm1;
	int dm2;
	float dm3;
	string dm4;

public:
	static void dm1Modify()
	{
		dm1++;
	}

	Test()
	{
		dm1Modify();
		dm2 = 0;
		dm3 = 0;
		dm4.assign("");
	}

	void setDm2(int inputDm2)
	{
		inputDm2 = dm2;
	}

	int getDm2() const
	{
		return dm2;
	}

	void setDm3(float inputDm3)
	{
		inputDm3 = dm3;
	}

	float getDm3() const
	{
		return dm3;
	}

	void setDm4(string inputDm4)
	{
		dm4.assign(inputDm4);
	}

	string getDm4() const
	{
		return dm4;
	}

	void printDm1()  const
	{
		cout << "dm1: " << dm1.getDay() << "-" << dm1.getMonth() << "-" << dm1.getYear() << endl;
	}

	void print()  const
	{
		cout << "dm1: " << dm1.getDay() << "-" << dm1.getMonth() << "-" << dm1.getYear() << endl;
		cout << "dm2: " << dm2 << endl;
		cout << "dm3: " << dm3 << endl;
		cout << "dm4: " << dm4 << endl;
	}

	~Test()
	{
		dm1Modify();
		
		printDm1();
	}
};

date Test::dm1(4, 11, 2001);

int main()
{
	Test obj;

	obj.printDm1();

	obj.dm1Modify();

	obj.printDm1();

	return 0;

	system("pause>0");
}