#include "BigInt.h"

std::string add(const std::string& s1, const std::string& s2)
{
	std::string resultStr;
	const std::string& longer = (s1.length() > s2.length()) ? s1 : s2;
	const std::string& shorter = (longer == s2) ? s1 : s2;

	USINT carry = 0;
	size_t lengthDiff = longer.length() - shorter.length();

	auto i1 = s1.rbegin();
	auto i2 = s2.rbegin();
	for ( ; (i1 != s1.rend()) || (i2 != s2.rend()); )
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
