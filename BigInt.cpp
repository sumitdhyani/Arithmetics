#include "BigInt.h"

std::string add(const std::string& s1, const std::string& s2, bool isNegative1, bool isNegative2)
{
	std::string resultStr;
	USINT carry = 0;

	auto i1 = s1.rbegin();
	auto i2 = s2.rbegin();
	while( (i1 != s1.rend()) || (i2 != s2.rend()) )
	{
		USINT t1 = 0;
		USINT t2 = 0;
		if (i1 != s1.rend())
		{
			t1 = *i1 - ASCII_DIGIT_OFFSET;
			i1++;
		}

		if(i2 != s2.rend())
		{
			t2 = *i2 - ASCII_DIGIT_OFFSET;
			i2++;
		}

		USINT res = t1 + t2 + carry;
		carry = res / 10;
		res %= 10;
		resultStr.insert( resultStr.begin(), res + ASCII_DIGIT_OFFSET );
	}

	if (carry > 0)
		resultStr = ((char)(carry + ASCII_DIGIT_OFFSET)) + resultStr;

	return resultStr;
}

std::string add(const std::string& s1, LLINT num, bool isNegative)
{
	std::string resultStr;
	USINT carry = 0;

	auto i = s1.rbegin();
	while ( (i != s1.rend()) || (num > 0))
	{
		USINT t1 = 0;
		if (i != s1.rend())
		{
			t1 = *i - ASCII_DIGIT_OFFSET;
			i++;
		}

		USINT t2 = num%10;
		num /= 10;

		USINT res = t1 + t2 + carry;
		carry = res / 10;
		res %= 10;
		resultStr.insert(resultStr.begin(), res + ASCII_DIGIT_OFFSET);
	}

	if (carry > 0)
		resultStr = ((char)(carry + ASCII_DIGIT_OFFSET)) + resultStr;

	return resultStr;
}

std::string subtract(const std::string& s1, LLINT num, bool isNegative)
{
	num = abs
	std::string resultStr;
	USINT carry = 0;

	auto i = s1.rbegin();
	while ((i != s1.rend()) || (num > 0))
	{
		USINT t1 = 0;
		if (i != s1.rend())
		{
			t1 = *i - ASCII_DIGIT_OFFSET;
			i++;
		}

		USINT t2 = num % 10;
		num /= 10;

		USINT res = t1 + t2 + carry;
		carry = res / 10;
		res %= 10;
		resultStr.insert(resultStr.begin(), res + ASCII_DIGIT_OFFSET);
	}

	if (carry > 0)
		resultStr = ((char)(carry + ASCII_DIGIT_OFFSET)) + resultStr;

	return resultStr;
}

	if (carry > 0)
		resultStr = ((char)(carry + ASCII_DIGIT_OFFSET)) + resultStr;

	return resultStr;
}

bool operator<(const std::string& str, LLINT num)
{
	bool res = false;
	num = abs(num);
	auto i = str.begin();
	USINT n1, n2;
	while( (num > 0) || (i != str.end()) )
	{
		n1 = num;
		n2 = (i == str.end())? 0 : 
		if (num == 0)
			return true
		else if (i == str.end())
			return false;
	}
}