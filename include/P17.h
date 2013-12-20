#ifndef __P17_h__
#define __P17_h__

#include "utils.h"

/*
If the numbers 1 to 5 are written out in words: 
one, two, three, four, five, then there are 
3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) 
inclusive were written out in words, how many 
letters would be used?
NOTE: Do not count spaces or hyphens. For example, 
342 (three hundred and forty-two) contains 23 letters 
and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in 
compliance with British usage.
*/

class P17
{
public:

	unsigned int answer()
	{
		// We don't say 'twenty zero', etc. 
		// The number 0 is not pronounced
		unsigned int oneToNineteen[] = {0, 3, 3, 5, 4, 4, 3, 5,
										5, 4, 3, 6, 6, 8, 8, 7,
										7, 9, 8, 8};
		unsigned int tensDigits[] = {6, 6, 5, 5, 5, 7, 6, 6};
		unsigned int hundredAnd = 10;
		unsigned int hundred = 7;

		unsigned int sum = 0;
		for (unsigned int i = 1; i < 1000; ++i)
		{
			// Handle ones and tens
			if (i % 100 < 20)
				sum += oneToNineteen[i % 100];
			else
			{
				static unsigned int idx = 0;
				sum += oneToNineteen[idx++];

				if (idx > 9)
					idx = 0;
			}

			// Handle 'one hundred and', 'two hundred and', etc.
			if (i / 100 > 0)
			{
				sum += oneToNineteen[i / 100];

				// If we land right on 100, 200, etc. we shouldn't need 'and'
				if ( !(i % 100) )
					sum += hundred;
				else
					sum += hundredAnd;
			}

			// Handle tens digits
			if (i % 100 >= 20)
				sum += tensDigits[unsigned int( floor( double(i % 100 - 20) / 10.0 ) )];
		}

		// Manually add 'one thousand'
		sum += 11;

		return sum;
	}

private:
};

#endif