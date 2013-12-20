#ifndef __P4_h__
#define __P4_h__

#include "utils.h"

/*
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 
2-digit numbers is 9009 = 91 × 99. Find the largest 
palindrome made from the product of two 3-digit numbers.
*/

class P4
{
public:

	unsigned int answer()
	{
		std::vector<unsigned int> palindromes;

		// Only need to consider 3 digit numbers
		for (unsigned int i = 100; i < 1000; ++i)
			for (unsigned int j = i; j < 1000; ++j)
				if ( isPalindrome(i * j) )
					palindromes.push_back(i * j);

		// Return the largest, if one exists
		if (palindromes.size() > 0)
		{
			std::sort( palindromes.begin(), palindromes.end() );
			return palindromes.back();
		}
		
		return 0;
	}

private:
	
	bool isPalindrome(unsigned int num)
	{
		// Break the number into individual digits
		std::vector<unsigned int> digits;
		while (num != 0)
		{
			unsigned int digit = num - 10 * (unsigned int)floor( (double)num / 10.0 );
			digits.push_back(digit);

			num -= digit;
			num /= 10;
		}

		// Check if the digits form a palindrome
		unsigned int iter = 0;
		while ( iter * 2 < digits.size() )
		{
			if ( digits[iter] != digits[digits.size() - iter - 1])
				return false;

			iter++;
		}

		return true;
	}
};

#endif