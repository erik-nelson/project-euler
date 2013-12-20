#ifndef __P24_h__
#define __P24_h__

#include "utils.h"

/*
A permutation is an ordered arrangement of objects. 
For example, 3124 is one possible permutation of the 
digits 1, 2, 3 and 4. If all of the permutations are 
listed numerically or alphabetically, we call it 
lexicographic order. The lexicographic permutations 
of 0, 1 and 2 are:
012   021   102   120   201   210

What is the millionth lexicographic permutation of the 
digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

class P24
{
public:

	uint64_t answer()
	{
		// Initialize a vector with the values 0,...,9
		static const unsigned int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::vector<unsigned int> elements(arr, arr  + sizeof(arr) / sizeof(arr[0]) );
		
		// Loop through until the 1,000,000th lexicographic permutation
		unsigned int iter = 1;
		while (iter != one_million)
		{
			unsigned int i = elements.size() - 2;
			for ( ; i >= 0; --i)
			{
				if ( elements[i] < elements[i+1] )
					break;
			}
			if (elements.size() - 2 < 0)
				break;

			unsigned int j = elements.size() - 1;
			for ( ; ; --j)
			{
				if ( elements[i] < elements[j] )
					break;
			}

			// Swap the two elements that need rearranging
			std::swap( elements[i], elements[j] );
			std::reverse( elements.begin() + i + 1, elements.end() );

			iter++;
		}

		// Concatenate terms in the vector
		uint64_t answer = 0;
		std::reverse( elements.begin(), elements.end() );
		for (unsigned int i = 0; i < elements.size(); ++i)
			answer += pow(10, i) * elements[i];

		return answer;
	}

private:
	static const unsigned int one_million = 1000000;
};

#endif