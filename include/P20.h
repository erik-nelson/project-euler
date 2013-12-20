#ifndef __P20_h__
#define __P20_h__

#include "utils.h"

/*
n! means n × (n − 1) × ... × 3 × 2 × 1
For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 
3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

class P20
{
public:

	uint64_t answer()
	{
		Utils::bigint one_hundred = Utils::intToBigint(100);
		Utils::bigint factorial = Utils::bigintFactorial(one_hundred);

		uint64_t sum = 0;
		for (Utils::bigint::const_iterator it = factorial.begin();
			 it != factorial.end(); ++it)
			 sum += *it;

		return sum;
	}

private:
};

#endif