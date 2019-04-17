#pragma once

#include <vector>


typedef char chach_t;


namespace BigNumber
{
	class BigNumber
	{
	private:

		std::vector<chach_t> number;

		bool negative, zero;
		
		void incrementing(std::vector<chach_t>::iterator _it, std::vector<chach_t>::iterator _itBegin);
		void decrementing(std::vector<chach_t>::iterator _it, std::vector<chach_t>::iterator _itBegin);

	public:

		BigNumber();
		BigNumber(std::string arg);

		BigNumber& operator = (BigNumber& arg);
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
	};
}