#ifndef __P22_h__
#define __P22_h__

#include "utils.h"

/*
Using names.txt (right click and 'Save Link/Target As...'), 
a 46K text file containing over five-thousand first names, 
begin by sorting it into alphabetical order. Then working out 
the alphabetical value for each name, multiply this value by 
its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, 
COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th 
name in the list. So, COLIN would obtain a score of 
938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

class P22
{
public:

	uint64_t answer()
	{
		loadNames();

		// ASCII capital letter offset = 64.
		// i.e. ASCII code for A is 65 - 64 = 1
		// likewise, Z is 90 - 64 = 26
		const unsigned int capital_offset = 64;
		uint64_t sum_of_namescores, rank;
		rank = sum_of_namescores = 0;
		for (std::set<std::string>::const_iterator it = sorted_names.begin();
		 	 it != sorted_names.end(); ++it)
		{
			rank++;

			unsigned int namescore = 0;
			for (unsigned int j = 0; j < (*it).size(); ++j)
				namescore += static_cast<int>( (*it)[j] ) - capital_offset;

			namescore *= rank;

			sum_of_namescores += namescore;
		}
			
		return sum_of_namescores;
	}

private:

	void loadNames()
	{
		std::ifstream filein("data/P22.txt");
		if (filein)
		{
			std::string name;
			while( !filein.eof() )
			{
				getline(filein, name, ',');
				sorted_names.insert( name.substr(1, name.size() - 2) );
			}

			filein.close();
		}
	}

	// Sets automatically sort upon insertion (binary tree)
	std::set<std::string> sorted_names;
};

#endif