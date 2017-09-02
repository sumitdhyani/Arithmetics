#include <math.h>
#include <iostream>
#include "CommonUtils.h"

//LLINT HCF(LLINT n1, LLINT n2)
//{
//	if ((0 == n1) || (0 == n2))
//		throw std::runtime_error("Attemting to find HCF of 0!");
//
//	n1 = abs(n1);
//	n2 = abs(n2);
//
//	while (n1 != n2)
//	{
//		if (n1 > n2)
//			n1 -= n2;
//		else
//			n2 -= n1;
//	}
//
//	return n1;
//}


LLINT HCF(LLINT n1, LLINT n2)
{
	if ((0 == n1) || (0 == n2))
		throw std::runtime_error("Attemting to find HCF of 0!");

	n1 = abs(n1);
	n2 = abs(n2);
	LLINT larger = (abs(n1 + n2) + abs(n1 - n2)) / 2;
	LLINT smaller = n1 + n2 - larger;
	while (smaller != larger)
	{
		LLINT x = (larger - smaller);
		LLINT y = smaller;
		LLINT ceil = 1 + (x - 1) / y;
		larger -= (smaller * ceil);

		LLINT temp = smaller;
		smaller = larger;
		larger = temp;
	}

	return smaller;
}

LLINT LCM(LLINT n1, LLINT n2)
{
	if ( (0 == n1) || (0 == n2) )
		return 0;

	//Considering the absolute values only
	//For example if numbers are -4, 3 then smaller = 3 and larger = 4
	LLINT smaller = abs((abs(n1 + n2) - abs(n1 - n2)) / 2);
	LLINT initialLarger = (abs(n1 + n2) + abs(n1 - n2)) / 2;
	LLINT larger = initialLarger;

	while( 0 != (larger % smaller) )
		larger += initialLarger;

	if ( (n1 < 0) || (n2 < 0) )
		return -larger;
	else
		return larger;
}
