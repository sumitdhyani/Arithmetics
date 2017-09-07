#pragma once
#include "ConstTypeDefsMacrdos.h"
#include <iostream>
#include <string>
//class BigInt
//{
//	std::string _integer;
//	bool _isNegative;
//
//	BigInt(LLINT integer)
//	{
//		_isNegative = (0 > integer);
//		integer = abs(integer);
//
//		do
//		{
//			_integer.insert(_integer.begin(), CHARACTER_ZERO + integer % 10);
//			integer /= 10;
//		} while (0 != integer);
//	}
//
//	void print()
//	{
//		std::cout << _integer;
//	}
//
//	BigInt operator+(const BigInt& bigInt)
//	{
//		size_t len = _integer.length() > bigInt._integer.length() ? _integer.length() : bigInt._integer.length();
//	}
//
//	BigInt(const std::string& integer, bool isNegative)
//	{
//		if (integer.empty())
//			throw std::runtime_error("Empty String!");
//
//		_integer = integer;
//		_isNegative = isNegative;
//	}
//
//	std::string add(const std::string& s1, const std::string& s2)
//	{
//		size_t len1 = s1.length();
//		size_t len2 = s2.length();
//		size_t len = (len1 > len2) ? len1 : len2;
//
//		std::string res;
//		for (size_t i = len - 1; i >= 0; i--)
//		{
//			char temp = (s1[i] + s2[i] - ASCII_DIGIT_OFFSET)
//			res.insert(res.begin(), );
//		}
//		USINT addition = 
//
//	}
//};

std::string add(const std::string& s1, const std::string& s2);