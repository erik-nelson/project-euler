#ifndef __P6_h__
#define __P6_h__

#include "utils.h"

/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the 
first ten natural numbers and the square of the sum is 
3025 − 385 = 2640.

Find the difference between the sum of the squares of the first 
one hundred natural numbers and the square of the sum.
*/

class P6
{
public:

	uint64_t answer()
	{
		return squareOfSum(100) - sumOfSquares(100);
	}

private:

	uint64_t sumOfSquares(const unsigned int& index)
	{
		uint64_t sum = 0;
		for (uint64_t i = 1; i <= index; ++i)
			sum += i*i;

		return sum;
	}

	uint64_t squareOfSum(const unsigned int& index)
	{
		uint64_t square = 0;
		for (uint64_t i = 1; i <= index; ++i)
			square += i;

		return square * square;
	}
};

#endif