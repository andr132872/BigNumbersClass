#include "pch.h"

#include <iostream>

#include "BigNumber.h"


BigNumber::BigNumber::BigNumber()
{
}


BigNumber::BigNumber::BigNumber(std::string arg)
{
	try
	{
		std::string::iterator it = arg.begin(), itEnd = arg.end();

		if (!isdigit(*it) || *it != '-')
			throw "000";

		++it;

		while (it++ != itEnd)
			if (!isdigit(*it))
				throw "000";

		it = arg.begin();

		if (*it == '-')
		{
			negative = true;
			zero = false;

			arg.erase(it);
		}
		else if ((number.size() == 1) && (*(--number.end()) == 0))
		{
			negative = false;
			zero = true;
		}
		else
		{
			negative = false;
			zero = false;
		}

		it = arg.begin();

		while (it++ != itEnd)
			number.push_back(*it);
	}

	catch (const char* error)
	{
		std::cout << "\aError #" << error << '\n';
	}
}


void BigNumber::BigNumber::incrementing(std::vector<chach_t>::iterator _it, std::vector<chach_t>::iterator _itBegin)
{
	if (!negative)
	{
		--_it;

		if (*_it == '9')
		{
			*_it = '0';

			if (!(_it == _itBegin))
				incrementing(_it, _itBegin);
			else
				number.insert(_itBegin, '1');
		}
		else
			++(*_it);
	}
	else
		decrementing(_it, _itBegin);
}


void BigNumber::BigNumber::decrementing(std::vector<chach_t>::iterator _it, std::vector<chach_t>::iterator _itBegin)
{
	if (!negative)
	{
		--_it;

		if (*_it == '0')
		{
			*_it = '9';

			if (!(_it == _itBegin))
				decrementing(_it, _itBegin);
			else
				number.insert(_itBegin, '1');
		}
		else
			--(*_it);
	}
	else
		incrementing(_it, _itBegin);
}


BigNumber::BigNumber& BigNumber::BigNumber::operator = (BigNumber arg)
{
	number = arg.number;
	zero = arg.zero;
	negative = arg.negative;

	return arg;
}


BigNumber::BigNumber& BigNumber::BigNumber::operator = (std::string arg)
{
	try
	{
		std::string::iterator it = arg.begin(), itEnd = arg.end();

		if (!isdigit(*it) || *it != '-')
			throw "000";

		++it;

		while (it++ != itEnd)
			if (!isdigit(*it))
				throw "000";

		it = arg.begin();

		if (*it == '-')
		{
			negative = true;
			zero = false;

			arg.erase(it);
		}
		else if ((number.size() == 1) && (*(--number.end()) == 0))
		{
			negative = false;
			zero = true;
		}
		else
		{
			negative = false;
			zero = false;
		}


		it = arg.begin();

		while (it++ != itEnd)
			number.push_back(*it);
	}

	catch (const char* error)
	{
		std::cout << "\aError #" << error << '\n';
	}

	return *this;
}


BigNumber::BigNumber& BigNumber::BigNumber::operator + (BigNumber arg)
{
}


BigNumber::BigNumber& BigNumber::BigNumber::operator - (BigNumber arg)
{
}


BigNumber::BigNumber& BigNumber::BigNumber::operator * (BigNumber arg)
{
}


BigNumber::BigNumber& BigNumber::BigNumber::operator / (BigNumber arg)
{
}


BigNumber::BigNumber& BigNumber::BigNumber::operator += (BigNumber arg)
{
}


BigNumber::BigNumber& BigNumber::BigNumber::operator -= (BigNumber arg)
{
}


BigNumber::BigNumber& BigNumber::BigNumber::operator *= (BigNumber arg)
{
}


BigNumber::BigNumber& BigNumber::BigNumber::operator /= (BigNumber arg)
{
}


BigNumber::BigNumber& BigNumber::BigNumber::operator ++ ()
{
	std::vector<chach_t>::iterator it = number.end();

	incrementing(number.end(), number.begin());

	return *this;
}


BigNumber::BigNumber& BigNumber::BigNumber::operator -- ()
{
}


std::ostream& BigNumber::operator << (std::ostream& out, BigNumber arg)
{
	std::vector<chach_t>::iterator it = arg.number.begin(), itEnd = arg.number.end();

	while (it++ != itEnd)
		std::cout << *it;

	return out;
}