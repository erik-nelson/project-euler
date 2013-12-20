#ifndef __utils_h__
#define __utils_h__

#include <cstdint> // For big ints
#include <vector>
#include <algorithm> // For vector sorting
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>
#include <numeric>
#include <set>

/******************************
* A header full of handy utils
* helper functions, and common
* math constants
******************************/

namespace Utils {

	/* Helpful constants */
	const double PI()      { return 3.1415926536; }
	const double TWOPI()   { return 6.2831853072; }
	const double PITWO()   { return 1.5707963268; }
	const double PITHREE() { return 1.0471975512; }
	const double PIFOUR()  { return 0.7853981634; }
	const double PISIX()   { return 0.5235987756; }
	const double EULER()   { return 2.7182818285; }

	/* Fibonacci Series */
	uint64_t fibonacci(const uint64_t& term)
	{
		return term < 2 ? term : fibonacci(term - 1) + fibonacci(term - 2);
	}

	/* Check if a number is prime */
	bool isPrime(const uint64_t& number)
	{
		// 1, 0, and negativs are not prime
		if (number <= 1)
			return false;

		// Check 2 first, we will skip when looping
		if (number % 2 == 0)
			if (number == 2)
				return true;
			else
				return false;

		// Only need to check up to square root
		uint64_t iter = 3;
		while (iter * iter <= number)
		{
			if ( !(number % iter) )
				return false;

			// Increment the iterator, skip mults of 2
			if (++iter % 2 == 0)
				iter++;
		}

		// Couldn't find any prime factors
		// This number must be prime
		return true;
	}

	/* Get smallest and largest factors of a number */
	bool getFactors(uint64_t& fac1, 
					uint64_t& fac2, 
					const uint64_t& number)
	{
		uint64_t iter = 2;

		// Only need to check up to square root
		while (iter * iter <= number)
		{
			if (number % iter == 0)
			{
				fac1 = iter;
				fac2 = number / iter;
				return true;
			}

			iter++;
		}

		// Couldn't find any prime factors
		return false;
	}

	/* Get all divisors of a number */
	std::vector<uint64_t> getAllFactors(const uint64_t& num)
	{
		std::vector<uint64_t> factors;

		// Number must be natural
		if (num < 1)
			return factors;

		// Don't duplicate if num is 1
		if (num == 1)
		{
			factors.push_back(1);
			return factors;
		}

		uint64_t iter = 1;

		// Only need to check up to square root
		while (iter * iter <= num)
		{
			if (num % iter == 0)
			{
				factors.push_back(iter);
				factors.push_back(num / iter);
			}

			iter++;
		}

		std::sort( factors.begin(), factors.end() );
		return factors;
	}

	std::vector<uint64_t> getUniqueFactors(const uint64_t& number)
	{
		std::vector<uint64_t> factors = getAllFactors(number);

		// Sort and get unique factors
		std::sort( factors.begin(), factors.end() );
		std::vector<uint64_t>::iterator it;
		it = std::unique ( factors.begin(), factors.end() );
		factors.resize( std::distance( factors.begin(), it) );

		return factors;
	}

	/* Get prime factors of a number */
	std::vector<uint64_t> getPrimeFactors(const uint64_t& number)
	{
		uint64_t fac1(0), fac2(0);
		std::vector<uint64_t> prime_factors;

		// Start with the big number, 
		// factor into 2 other numbers. The first is
		// guaranteed to be prime if a prime factor exists
		getFactors(fac1, fac2, number);
		prime_factors.push_back(fac1);

		// Widdle the second factor down into 2 factors each time
		while ( getFactors(fac1, fac2, fac2) )
			prime_factors.push_back(fac1);

		// Store the final prime factor from the last iteration
		prime_factors.push_back(fac2);

		std::sort( prime_factors.begin(), prime_factors.end() );
		return prime_factors;
	}

	/* Perform a sigma summation over all numbers up to this one */
	uint64_t sigmaSummation(const uint64_t& num)
	{
		if (num <= 0)
			return 0;

		return (num == 1) ? num : num + sigmaSummation(num-1);
	}

	/* Recursive factorial */
	uint64_t factorial(const uint64_t& num)
	{
		if (num <= 0)
			return 0;

		return (num == 1) ? 1 : num * factorial(num - 1);
	}

	/* Big int operations */
	typedef std::vector<char> bigint;

	template<typename T>
	bigint intToBigint(const T& in)
	{
		uint64_t num = static_cast<uint64_t>(in);
	
		// Break the number into individual digits
		bigint digits;
		while (num != 0)
		{
			uint64_t digit = num - 10 * static_cast<uint64_t>( floor( (long long)num / 10.0 ) );
			digits.push_back( static_cast<char>(digit) );

			num -= digit;
			num /= 10;
		}

		std::reverse( digits.begin(), digits.end() );
		return digits;
	}

	/* Addition */
	bigint bigintAdd(const bigint& term1, const bigint& term2)
	{
		bigint sum;

		// Make sure both are positive... for now
		for (bigint::const_iterator it = term1.begin(); it != term1.end(); ++it)
			assert(*it >= 0);
		for (bigint::const_iterator it = term2.begin(); it != term2.end(); ++it)
			assert(*it >= 0);

		// Make sure term1 has more digits
		bigint term1_temp(term1), term2_temp(term2);
		if ( term2.size() > term1.size() )
		{
			term1_temp = term2;
			term2_temp = term1;
		}
		std::reverse( term1_temp.begin(), term1_temp.end() );
		std::reverse( term2_temp.begin(), term2_temp.end() );

		int carry = 0;
		for (unsigned int i = 0; i < term1_temp.size(); ++i)
		{
			int digit;
			if ( i >= term2_temp.size() )
			{
				digit = term1_temp[i] + carry;
				carry = 0;
				if (digit > 9)
				{
					digit -= 10;
					carry = 1;
				}
			}
			else
			{
				digit = term1_temp[i] + term2_temp[i] + carry;
				carry = 0;
				if (digit > 9)
				{
					carry = 1;
					digit -= 10;
				}
			}

			sum.push_back(digit);
		}

		if (carry == 1)
			sum.push_back(1);

		std::reverse( sum.begin(), sum.end() );
		return sum;
	}

	/* Subtraction */
	bigint bigintSubtract(const bigint& term1, const bigint& term2)
	{
		bigint difference;

		// No negatives allowed... for now. This check misses some cases still.
		assert( term1.size() >= term2.size() );

		bigint term1_temp(term1), term2_temp(term2);
		std::reverse(term1_temp.begin(), term1_temp.end());
		std::reverse(term2_temp.begin(), term2_temp.end());

		int carry = 0;
		for (unsigned int i = 0; i < term1_temp.size(); ++i)
		{
			if ( i >= term2_temp.size() )
			{
				if (carry == 0)
					difference.push_back( term1_temp[i] );
				else 
				{
					int digit = term1_temp[i] - carry;
					if (digit < 0)
					{
						digit = 10 - abs(digit);
						carry = 1;
					}
					else
						carry = 0;

					difference.push_back(digit);
				}
			}
			else
			{
				int digit;
				if (carry != 0)
					digit = term1_temp[i] - (term2_temp[i] + carry);
				else
					digit = term1_temp[i] - term2_temp[i];

				if (digit < 0)
				{
					digit = 10 - abs(digit);
					carry = 1;
				}
				else
					carry = 0;

				difference.push_back(digit);
			}
		}

		while( difference.back() == 0 && difference.size() > 1 )
			difference.pop_back();

		std::reverse( difference.begin(), difference.end() );
		return difference;
	}

	/* Multiplication */
	bigint bigintMultiply(const bigint& multiplier, const bigint& multiplicand)
	{
		bigint product; product.push_back(0);

		// Make sure both are positive... for now
		for (bigint::const_iterator it = multiplier.begin(); it != multiplier.end(); ++it)
			assert(*it >= 0);
		for (bigint::const_iterator it = multiplicand.begin(); it != multiplicand.end(); ++it)
			assert(*it >= 0);

		// Make sure term1 has more digits
		bigint term1(multiplier), term2(multiplicand);
		if ( multiplicand.size() > multiplier.size() )
		{
			term1 = multiplicand;
			term2 = multiplier;
		}
		std::reverse( term1.begin(), term1.end() );
		std::reverse( term2.begin(), term2.end() );

		// Perform the multiplication
		std::vector<bigint> nums_to_add;
		for (unsigned int i = 0; i < term2.size(); ++i)
		{
			bigint add;

			// Store preceding zeros
			for (unsigned int iter = 0; iter < i; ++iter)
				add.push_back(0);

			int carry = 0;
			for (unsigned int j = 0; j < term1.size(); ++j)
			{
				int digit = term1[j] * term2[i] + carry;
				carry = 0;
				if (digit > 9)
				{
					carry = digit / 10;
					digit -= 10 * (digit / 10);
				}
				add.push_back(digit);
			}

			if (carry > 0)
				add.push_back(carry);

			std::reverse( add.begin(), add.end() );
			nums_to_add.push_back(add);
		}

		// Add all multiplication terms together
		for (std::vector<bigint>::iterator it = nums_to_add.begin();
			it != nums_to_add.end(); ++it)
			product = bigintAdd(product, *it);

		return product;
	}

	/* Multiplies a big int by two */
	void bigintDouble(bigint& multiplicand)
	{
		int carry = 0;
		for (bigint::iterator it = multiplicand.begin();
			it != multiplicand.end(); ++it)
		{
			*it = *it * 2;
			*it += carry;
			carry = (*it >= 10);
			*it -= carry * 10;			
		}
		if (carry != 0)
			multiplicand.push_back(carry);
	}

	/* Recursive big int factorial */
	bigint bigintFactorial(const bigint& num)
	{
		bigint out;
		if (num.size() == 1 && num[0] <= 0)
		{
			out.push_back(0);
			return out;
		}
		
		if (num.size() == 1 && num[0] == 1)
		{
			out.push_back(1);
			return out;
		}
	
		bigint one; one.push_back(1);
		bigint num_minus_one = bigintSubtract(num, one);	
		out = bigintMultiply( num, bigintFactorial(num_minus_one) );
		return out;
	}

	/* Big int fibonacci. Recursion is extremely slow... fix this up */
	bigint bigintFibonacci(const bigint& term)
	{
		bigint out;
		if (term.size() == 1 && term[0] < 2)
		{
			out.push_back( term[0] );
			return out;
		}
		else
		{
			bigint one, two;
			one.push_back(1);
			two.push_back(2);
			out = bigintAdd( bigintFibonacci( bigintSubtract(term, one) ), 
				             bigintFibonacci( bigintSubtract(term, two) ) );
			return out;
		}
	}

};

#endif