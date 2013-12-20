#ifndef __P19_h__
#define __P19_h__

#include "utils.h"

/*
You are given the following information, but you 
may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.

- Thirty days has September,
  April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.

- A leap year occurs on any year evenly divisible by 4, 
  but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during 
the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

class P19
{
public:

	unsigned int answer()
	{
		// Starts on monday, but immediately increment to Tuesday
		unsigned int days_until_sunday = 5; 
		unsigned int sundays_on_first = 0;
		unsigned int year = 1901;
		unsigned int month = 1;
		unsigned int day = 1;
		bool leap_year = false;

		while (year != 2000 || month != 12 || day != 31)
		{
			day++;
			
			// September, April, June, and November
			if (month == 9 || month == 4 || month == 6 || month == 11)
			{
				if (day > 30)
				{
					day = 1;
					month++;
				}
			}

			// February
			else if (month == 2 && leap_year)
			{
				if (day > 29)
				{
					day = 1;
					month++;
				}
			}
			else if (month == 2 && !leap_year)
			{
				if (day > 28)
				{
					day = 1;
					month++;
				}
			}

			// January, March, May, July, August, October, December
			else
			{
				if (day > 31)
				{
					day = 1;
					month++;
				}
			}

			// Increment the year counter
			if (month > 12)
			{
				month = 1;
				year++;
				
				if (year % 4 == 0)
					leap_year = true;
				else
					leap_year = false;

				if (year % 100 == 0)
				{
					if (year % 400 == 0)
						leap_year = true;
					else
						leap_year = false;
				}
			}

			// Check if it is sunday the first
			days_until_sunday--;
			if (day == 1 && days_until_sunday == 0)
				sundays_on_first++;

			if (days_until_sunday == 0)
				days_until_sunday = 7;
		}

		return sundays_on_first;
	}

private:
};

#endif