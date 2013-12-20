#ifndef __P67_h__
#define __P67_h__

#include "utils.h"

/*
By starting at the top of the triangle below and 
moving to adjacent numbers on the row below, the 
maximum total from top to bottom is 23.
3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.
Find the maximum total from top to bottom in triangle.txt 
(right click and 'Save Link/Target As...'), a 15K text file 
containing a triangle with one-hundred rows.
NOTE: This is a much more difficult version of Problem 18. 
It is not possible to try every route to solve this problem, 
as there are 299 altogether! If you could check one trillion 
(1012) routes every second it would take over twenty billion 
years to check them all. There is an efficient algorithm to 
solve it. ;o)
*/

class P67
{
public:

	unsigned int answer()
	{
		// Populate the triangle data structure from file
		loadTriangle();

		// Work from the bottom up, collapsing slices as we go
		size_t tri_size = tri.size();
		for (size_t i = 0; i <= tri_size - 2; ++i)
			collapseSlice(tri);

		// Once everything is collapsed, tri only has one value: the max path
		return tri[0][0];
	}

private:

	typedef unsigned int tri_entry;
	typedef std::vector<tri_entry> tri_slice;
	typedef std::vector<tri_slice> triangle;
	triangle tri;

	void loadTriangle()
	{
		std::ifstream filein("data/P67.txt");
		if (filein)
		{
			unsigned int i = 0;
			std::string dummy;
			while( !filein.eof() )
			{
				tri_slice slice;
				for (unsigned int j = 0; j < i + 1; ++j)
				{
					tri_entry entry;
					filein >> entry;
					slice.push_back(entry);
				}
				tri.push_back(slice);
				i++;
			}

			filein.close();
		}
	}

	void collapseSlice(triangle& tri)
	{
		// Access the bottom and second to bottom slices.
		// Collapse them into a single slice by comparing
		// the costs from each child node to get to the parent above
		tri_slice lowest = tri.back();
		tri.pop_back();
		tri_slice second_lowest = tri.back();
		tri.pop_back();

		assert( lowest.size() > second_lowest.size() );

		tri_slice new_bottom;
		for (unsigned int i = 0; i < second_lowest.size(); ++i)
		{
			tri_entry entry = second_lowest[i] + std::max(lowest[i], lowest[i+1]);
			new_bottom.push_back(entry);
		}
		tri.push_back(new_bottom);

	}
};

#endif