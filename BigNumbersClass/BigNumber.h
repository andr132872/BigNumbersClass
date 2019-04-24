#pragma once

#include <vector>
#include <string>
#include <iostream>


namespace BigNumber
{
	typedef char chach_t;


	class BigNumber
	{
	public:

		std::vector<chach_t> number;

		bool negative = false, zero = false;
		
		void incrementing(std::vector<chach_t>::iterator _it, std::vector<chach_t>::iterator _itBegin);
		void decrementing(std::vector<chach_t>::iterator _it, std::vector<chach_t>::iterator _itBegin);

	public:

		BigNumber();
		BigNumber(std::string arg);

		BigNumber& operator = (BigNumber arg);
		BigNumber& operator = (std::string arg);
		BigNumber& operator + (BigNumber arg);
		BigNumber& operator - (BigNumber arg);
		BigNumber& operator * (BigNumber arg);
		BigNumber& operator / (BigNumber arg);
		BigNumber& operator += (BigNumber arg);
		BigNumber& operator -= (BigNumber arg);
		BigNumber& operator *= (BigNumber arg);
		BigNumber& operator /= (BigNumber arg);
		BigNumber& operator ++ ();
		BigNumber& operator -- ();
		friend BigNumber& operator ++ (BigNumber& arg);
		friend BigNumber& operator -- (BigNumber& arg);
		friend std::ostream& operator << (std::ostream& out, BigNumber arg);
	};
}