#ifndef __P21_h__
#define __P21_h__

#include "utils.h"

/*
Let d(n) be defined as the sum of proper 
divisors of n (numbers less than n which 
divide evenly into n). If d(a) = b and d(b) = a, 
where a ≠ b, then a and b are an amicable pair and 
each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 
1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 
therefore d(220) = 284. The proper divisors of 
284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

class P21
{
public:

	uint64_t answer()
	{
		// Hacky brute force implementation... but it works!!!
		std::vector<uint64_t> amicable_numbers;
		for (unsigned int i = 1; i < 10000; ++i)
		{
			std::vector<uint64_t> factors = Utils::getAllFactors(i);
			
			// Don't include the number itself as a divisor
			factors.pop_back();

			if (factors.size() > 0)
			{
				uint64_t sum_of_factors = std::accumulate( factors.begin(), 
														   factors.end(), 
														   0 );

				// Check if this is an amicable number
				std::vector<uint64_t> amicable_factors = Utils::getAllFactors(sum_of_factors);
			
				// Don't include the number itself as a divisor
				amicable_factors.pop_back();
				if (amicable_factors.size() > 0)
				{
					uint64_t sum_of_amicable_factors = std::accumulate( amicable_factors.begin(),
																		amicable_factors.end(),
																		0 );
					if (i == sum_of_amicable_factors && i != sum_of_factors)
					{
						amicable_numbers.push_back(i);

						// Only add the second amicable number if it is less than 10000
						// Also, only count each number once
						if (sum_of_factors < 10000)
							amicable_numbers.push_back(sum_of_factors);
					}
				}
			}
		}

		// Make sure all of our amicable numbers are unique
		std::sort( amicable_numbers.begin(), amicable_numbers.end() );
		std::vector<uint64_t>::iterator it;
		it = std::unique ( amicable_numbers.begin(), amicable_numbers.end() );
		amicable_numbers.resize( std::distance( amicable_numbers.begin(), it) );

		// Sum up the amicable numbers
		uint64_t sum = 0;
		for (std::vector<uint64_t>::const_iterator it = amicable_numbers.begin();
			it != amicable_numbers.end(); ++it)
			sum += *it;
		
		return sum;
	}

private:
};

#endif