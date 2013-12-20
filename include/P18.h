#ifndef __P18_h__
#define __P18_h__

#include "utils.h"

/*
By starting at the top of the triangle below 
and moving to adjacent numbers on the row below, 
the maximum total from top to bottom is 23.
3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.
Find the maximum total from top to bottom of the triangle below:
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to 
solve this problem by trying every route. However, Problem 67, 
is the same challenge with a triangle containing one-hundred rows; 
it cannot be solved by brute force, and requires a clever method! ;o)
*/

class P18
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
		std::ifstream filein("data/P18.txt");
		if (filein)
		{
			unsigned int i = 0;
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