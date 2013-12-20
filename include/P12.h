#ifndef __P12_h__
#define __P12_h__

#include "utils.h"

/*
The sequence of triangle numbers is generated 
by adding the natural numbers. So the 7th triangle 
number would be 
1 + 2 + 3 + 4 + 5 + 6 + 7 = 28

The first ten terms would be:
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:
 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.
What is the value of the first triangle number to have over five hundred divisors?
*/

class P12
{
public:

	uint64_t answer()
	{
		// Loop to infinity! 
		// the solution is guaranteed to exist
		for (uint64_t iter = 1; ; ++iter)
		{
			// Generate the triangular number
			uint64_t triangular_num = Utils::sigmaSummation(iter);

			// Get all of the factors of the triangular number
			std::vector<uint64_t> factors = Utils::getAllFactors(triangular_num);
			if (factors.size() > 500)
				return triangular_num;

			// Should probably include some upper bound...
			if (iter > 1000000)
				return 0;
		}
	}

private:
};

#endif