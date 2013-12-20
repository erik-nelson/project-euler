#ifndef __P15_h__
#define __P15_h__

#include "utils.h"

/*
Starting in the top left corner of a 2×2 grid, 
and only being able to move to the right and down, 
there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?
*/

class P15
{
public:

	uint64_t answer()
	{
		// We only have two options at each vertex: down or right
		// since there are 20 vertices in each dimension,
		// this means that the number of possible combinations must be
		// (20 + 20)! / (20! * 20!)
		double num_combos = 1;
		for (double i = 40; i > 20; i--)
			num_combos *= i / (i - 20);

		return static_cast<uint64_t>(num_combos);
	}

private:
};

#endif