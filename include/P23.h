#ifndef __P23_h__
#define __P23_h__

#include "utils.h"

/*
A perfect number is a number for which 
the sum of its proper divisors is exactly 
equal to the number. For example, the sum 
of the proper divisors of 28 would be 
1 + 2 + 4 + 7 + 14 = 28, which means that 28 
is a perfect number.

A number n is called deficient if the sum of 
its proper divisors is less than n and it is 
called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 
1 + 2 + 3 + 4 + 6 = 16, the smallest number
that can be written as the sum of two abundant
numbers is 24. By mathematical analysis, it can 
be shown that all integers greater than 28123 can 
be written as the sum of two abundant numbers. 
However, this upper limit cannot be reduced any 
further by analysis even though it is known that 
the greatest number that cannot be expressed as 
the sum of two abundant numbers is less than this
limit.

Find the sum of all the positive integers which 
cannot be written as the sum of two abundant numbers.
*/

class P23
{
public:

	uint64_t answer()
	{
		std::vector<uint64_t> abundant_nums, abundant_sums, answer_set;

		// Upper limit 28123 defined in problem statement
		for (unsigned int i = 1; i < 28123; ++i)
		{
			std::vector<uint64_t> factors = Utils::getUniqueFactors(i);
			factors.pop_back();

			uint64_t sum = std::accumulate( factors.begin(), factors.end(), 0 );
			if (sum > i)
			{
				// We have an abundant number
				abundant_nums.push_back(i);
			}

			answer_set.push_back(i);
		}

		// Store all possible abundant sums
		for (unsigned int i = 0; i < abundant_nums.size(); ++i)
			for (unsigned int j = 0; j < abundant_nums.size(); ++j)
				abundant_sums.push_back( abundant_nums[i] + abundant_nums[j] );

		// Sort and get unique abundant sums
		std::sort( abundant_sums.begin(), abundant_sums.end() );
		std::vector<uint64_t>::iterator it;
		it = std::unique ( abundant_sums.begin(), abundant_sums.end() );
		abundant_sums.resize( std::distance( abundant_sums.begin(), it) );

		// Find the set difference between the two
		std::set<uint64_t> difference;
		std::sort( answer_set.begin(), answer_set.end() );
		std::set_difference( answer_set.begin(), answer_set.end(),
							 abundant_sums.begin(), abundant_sums.end(),
							 std::inserter(difference, difference.end() ) );

		return std::accumulate( difference.begin(), difference.end(), 0);

	}

private:
};

#endif