#ifndef __P3_h__
#define __P3_h__

#include "utils.h"

/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

class P3
{
public:

	unsigned int answer()
	{
		std::vector<uint64_t> prime_factors =
			Utils::getPrimeFactors(600851475143);
		return static_cast<unsigned int>( prime_factors.back() );
	}

private:
};

#endif