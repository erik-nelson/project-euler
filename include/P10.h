#ifndef __P10_h__
#define __P10_h__

#include "utils.h"

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

class P10
{
public:

	uint64_t answer()
	{
		uint64_t sum = 0;
		for (uint64_t i = 1; i < two_million; i++)
			if (Utils::isPrime(i))
				sum += i;

		return sum;
	}

private:

	static const uint64_t two_million = 2000000;
};

#endif