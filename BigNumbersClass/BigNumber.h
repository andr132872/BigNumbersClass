#pragma once

#include <vector>
#include <string>



typedef chach_t char;



namespace BigNumber
{


	class BigNumber
	{
	private:

		std::vector<uint16_t> number;

		bool negative, zero;
		
		void incrementing(std::vector<uint16_t>::iterator _it, std::vector<uint16_t>::iterator _itBegin);

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