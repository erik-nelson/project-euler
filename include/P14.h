#ifndef __P14_h__
#define __P14_h__

#include "utils.h"

/*
The following iterative sequence is defined for the set of positive integers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) 
contains 10 terms. Although it has not been proved yet (Collatz Problem), 
it is thought that all starting numbers finish at 1. Which starting number, 
under one million, produces the longest chain? NOTE: Once the chain starts 
the terms are allowed to go above one million.
*/

class P14
{
public:

	unsigned int answer()
	{
		unsigned int max_chain_len, starting_num;
		starting_num = max_chain_len = 0;
		
		for (unsigned int i = 0; i < one_million; ++i)
		{
			unsigned int chain_len = 0;
			collatz(i, chain_len);

			if (chain_len > max_chain_len)
			{
				starting_num = i;
				max_chain_len = chain_len;
			}
		}

		return starting_num;
	}

private:

	// Recursively call the collatz function, adding
	// to chain_len on each iteration
	void collatz(const uint64_t& in,
				 unsigned int& chain_len)
	{
		// Error case
		if (in < 1)
		{
			chain_len = 0;
			return;
		}

		// Default return
		if (in == 1)
			return;

		if (in % 2 == 0)
			collatz(in / 2, chain_len);
		else
			collatz(3 * in + 1, chain_len);

		chain_len++;
	}

	static const unsigned int one_million = 1000000;
};

#endif