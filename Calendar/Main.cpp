#include <iostream>
#include <time.h>
#include <array>
using namespace std;

bool IsLeapYear(int year)
{
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

static int DaysInMonth(int month, int year)
{
	if (month == 2)
	{
		return IsLeapYear(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return 30;
		}
	else
	{
		return 31;
	}
}

int main()
{
	do
	{
		int year, month;
		cout << "Enter year: ";
		cin >> year;
		cout << "Enter month(1 - 12): ";
		cin >> month;

		int days = DaysInMonth(month, year);
		
		std::array<std::string, 13> monthNames = {"", "Jan" , "Feb", "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sep" , "Oct", "Nov", "Dec"};
		string monthName;
		if (month <= 12 && month >= 1)
		{
			monthName = monthNames[month];
		}
		
		cout << "\n============================\n";
		cout << "          " << monthName << " " << year << "\n";
		cout << "============================\n";
		cout << " Sun Mon Tue Wed Thu Fri Sat\n";

		tm time_in = {};
		time_in.tm_year = year - 1900;
		time_in.tm_mon = month - 1;
		time_in.tm_mday = 1;
		mktime(&time_in);
		int StartingDay = time_in.tm_wday;

		for (int i = 0; i < StartingDay; ++i)
		{
			cout << "    ";
		}

		for (int i = 1; i <= days; ++i)
		{
			cout << (i < 10 ? "  " : " ") << i << " ";

			if ((i + StartingDay) % 7 == 0 || i == days)
			{
				cout << "\n";
			}
		}
		cout << "\n";
	} while (true);
	return 0;
}
