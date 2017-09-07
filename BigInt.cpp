#include "BigInt.h"

std::string add(const std::string& s1, const std::string& s2)
{
	std::string resultStr;
	const std::string& longer = (s1.length() > s2.length()) ? s1 : s2;
	const std::string& shorter = (longer == s2) ? s1 : s2;

	USINT carry = 0;
	USINT lengthDiff = longer.length() - shorter.length();
	for (size_t i = shorter.length() - 1; i >= 0; i--)
	{
		USINT res = longer[i + lengthDiff] + shorter[i] + carry - 2 * ASCII_DIGIT_OFFSET;
		carry = res / 10;
		res %= 10;
		resultStr.insert( resultStr.begin(), res + ASCII_DIGIT_OFFSET );
	}

	for (size_t i = longer.length() - shorter.length() - 1; i >= 0; i--)
	{
		USINT res = longer[i] + carry - ASCII_DIGIT_OFFSET;
		carry = res / 10;
		res %= 10;
		resultStr.insert(resultStr.begin(), res + ASCII_DIGIT_OFFSET);
	}

	if (carry > 0)
		resultStr = ((char)(carry + ASCII_DIGIT_OFFSET)) + resultStr;

	return resultStr;
}