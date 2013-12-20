#include <iostream>
#include <cstdint> // For big ints

#include "P27.h"

int main (char** argv, int argc)
{

	P27 p27;
	auto answer = p27.answer();

	std::cout << "Answer is: " << answer << std::endl;

	return 1;
}