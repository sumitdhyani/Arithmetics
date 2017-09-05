#include "Fraction.h"

Fraction operator+(LLINT num, const Fraction& fraction)
{
	return (fraction + num);
}

Fraction operator-(LLINT num, const Fraction& fraction)
{
	return (-fraction + num);
}

Fraction operator*(LLINT num, const Fraction& fraction)
{
	return (fraction * num);
}

Fraction operator/(LLINT num, const Fraction& fraction)
{
	return (Fraction(num, 1) / fraction);
}

bool operator==(LLINT num, const Fraction& fraction)
{
	return (fraction == num);
}

bool operator!=(LLINT num, const Fraction& fraction)
{
	return (fraction != num);
}

bool operator<(LLINT num, const Fraction& fraction)
{
	return !(fraction <= num);
}

bool operator<=(LLINT num, const Fraction& fraction)
{
	return !(fraction < num);
}

bool operator>(LLINT num, const Fraction& fraction)
{
	return !(fraction >= num);
}

bool operator>=(LLINT num, const Fraction& fraction)
{
	return !(fraction > num);
}
