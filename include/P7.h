#ifndef __P7_h__
#define __P7_h__

#include "utils.h"

/*
By listing the first six prime numbers: 
2, 3, 5, 7, 11, and 13, we can see that 
the 6th prime is 13. What is the 10001st 
prime number?
*/

class P7
{
public:

	unsigned int answer()
	{
		unsigned int num_primes, iter;
		iter = num_primes = 0;

		while (num_primes != 10001)
			if( Utils::isPrime(++iter) )
				num_primes++;
			
		return iter;
	}

private:
};

#endif