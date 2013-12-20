#ifndef __P25_h__
#define __P25_h__

#include "utils.h"

/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

class P25
{
public:

	unsigned int answer()
	{
		Utils::bigint fibonacci_n1, fibonacci_n2;
		fibonacci_n1.push_back(1);
		fibonacci_n2.push_back(1);

		unsigned int iter = 2; // Starting on the third term

		while (fibonacci_n1.size() < 1000)
		{
			Utils::bigint temp = fibonacci_n1;
			fibonacci_n1 = Utils::bigintAdd(fibonacci_n1, fibonacci_n2);
			fibonacci_n2 = temp;
			iter++;
		}

		return iter;
	}

private:
};

#endif