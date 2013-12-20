#ifndef __P5_h__
#define __P5_h__

#include "utils.h"

/*
2520 is the smallest number that can be divided 
by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible 
by all of the numbers from 1 to 20?
*/

class P5
{
public:

	unsigned int answer()
	{
		// Loop indefinitely, 
		// we will eventually reach the solution
		for (unsigned int i = 1; ; ++i)
			if ( checkMod(i) )
				return i;
	}

private:

	bool checkMod(const unsigned int& num)
	{
		// Check to see if this number, 
		// modulus 1,...,20, is zero
		for (unsigned int j = 1; j < 20; ++j)
		{
			if (num % j != 0)
				return false;
		}

		return true;
	}
};

#endif