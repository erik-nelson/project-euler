#ifndef __P26_h__
#define __P26_h__

#include "utils.h"

/*
A unit fraction contains 1 in the numerator. The decimal 
representation of the unit fractions with denominators 2 to 10 are given:
1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. 
It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring 
cycle in its decimal fraction part.
*/

class P26
{
public:

	unsigned int answer()
	{
		// Assume evens will not produce the longest cycle
		unsigned int answer, max_cycle_length;
		answer = max_cycle_length = 0;
		for (unsigned int i = 1; i < 999; i += 2)
		{
			unsigned int dec = 1;
			for (unsigned int j = 0; j < i; ++j)
				dec = (dec * 10) % i;

			unsigned int dec_store = dec;
			unsigned int cycle_length = 0;
			do
			{
				dec = (dec * 10) % i;
				cycle_length++;
			} while (dec_store != dec);

			if (cycle_length > max_cycle_length)
			{
				answer = i;
				max_cycle_length = cycle_length;
			}
		}

		return answer;
	}

private:
};

#endif