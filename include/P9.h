#ifndef __P9_h__
#define __P9_h__

#include "utils.h"

/*
A Pythagorean triplet is a set of three natural numbers, 
a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which 
a + b + c = 1000. Find the product abc.
*/

class P9
{
public:

	unsigned int answer()
	{
		for (double a = 1; a < 500; ++a)
			for (double b = 1; b < 500; ++b)
			{
				double c = sqrt(a * a + b * b);
				if (ceil(c) == c || floor(c) == c)
					// We have a pythagorean triplet, check if sum is 1000
					if (static_cast<unsigned int>(a + b + c) == 1000)
						return static_cast<unsigned int>(a * b * c);
			}

		return 0;

	}

private:
};

#endif