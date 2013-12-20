#ifndef __P1_h__
#define __P1_h__

#include "utils.h"

/*
If we list all the natural numbers below 10
that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23. Find the sum of all 
the multiples of 3 or 5 below 1000.
*/

class P1
{
public:

	unsigned int answer()
	{
		unsigned int sum = 0;
		for (unsigned int i = 0; i < 1000; i++)
			if ( !(i % 3) || !(i % 5) )
				sum += i;

		return sum;
	}

private:
};

#endif