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
		day = inputDay;
	}

	void operator++()
	{
		day++;

		if (day > 31)
		{
			day = 1;
			month++;
		}

		if (month > 12)
		{
			month = 1;
			year++;
		}
	}

	int getDay() const
	{
		return day;
	}

	void setMonth(int inputMonth)
	{
		month = inputMonth;
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

date Test::dm1(3, 1, 2001);

int main()
{
	Test obj;

	obj.printDm1();

	obj.dm1Modify();

	obj.printDm1();

	return 0;

	system("pause>0");
}