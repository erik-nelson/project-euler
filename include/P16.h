#ifndef __P16_h__
#define __P16_h__

#include "utils.h"

/*
2^15 = 32768 and the sum of its digits is 
3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
*/

class P16
{
public:

	uint64_t answer()
	{
		// Store big ints as an std::vector<char>,
		// call 'double' 1000 times
		Utils::bigint answer;
		answer.push_back(1);
		for (unsigned int i = 0; i < 1000; ++i)
			Utils::bigintDouble(answer);

		uint64_t sum = 0;
		for (Utils::bigint::reverse_iterator it = answer.rbegin();
			it != answer.rend(); ++it)
			sum += static_cast<unsigned int>(*it);

		return sum;
	}

private:
};

#endif