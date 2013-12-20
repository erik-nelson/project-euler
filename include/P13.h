#ifndef __P13_h__
#define __P13_h__

#include "utils.h"

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
[number included in "data/P13.txt"]
*/

class P13
{
public:

	std::string answer()
	{
		std::ifstream filein("data/P13.txt");
		if (filein)
		{
			for (unsigned int i = 0; i < 100; i++)
				filein >> stringlines[i];

			filein.close();

			std::vector<unsigned int> digits;
			unsigned int hundreds, tens;
			hundreds = tens = 0;
			for (unsigned int i = 1; i <= 50; ++i)
			{
				unsigned int digit_sum = 0;
				for (unsigned int j = 0; j < 100; ++j)
					digit_sum += atoi( stringlines[j].substr(50-i, 1).c_str() );

				digit_sum += hundreds / 10 + tens / 10;

				hundreds = digit_sum / 100 * 100;
				tens = (digit_sum / 10 - hundreds / 10) * 10;
				
				digits.push_back(digit_sum - hundreds - tens);
			}

			digits.push_back(tens / 10);
			digits.push_back(hundreds / 100);

			// Reverse the vector so we have higher digits in front,
			// remove all elements except first 10
			std::reverse( digits.begin(), digits.end() );
			digits.erase(digits.begin() + 10, digits.end());

			// Turn into a string and return
			std::stringstream ss;
			for (std::vector<unsigned int>::iterator it = digits.begin();
				it != digits.end(); ++it)
				ss << *(it);

			return ss.str();
		}

		// If file won't open
		return 0;
	}

private:
	std::string stringlines[100];
};

#endif