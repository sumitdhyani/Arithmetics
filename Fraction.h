#pragma once
#include <iostream>
#include "CommonUtils.h"

class Fraction
{
protected:
	LLINT _num;
	LLINT _denom;
public:
	Fraction(LLINT num, LLINT denom)
	{
		if (0 == denom)
			throw std::runtime_error("Denominator provided 0");

		_num = num;
		_denom = denom;

		simplify();
	}

	void simplify()
	{
		if (0 == _num)
			_denom = 1;
		else
		{
			//Reduction
			LLINT hcf = HCF(_num, _denom);
			_num /= hcf;
			_denom /= hcf;

			//Sign simplification
			bool sameSign = ((_num > 0) == (_denom > 0));
			_num = abs(_num);
			_denom = abs(_denom);
			if (!sameSign)
				_num = -_num;
		}
	}

	virtual ~Fraction() {}

	

	Fraction operator +=(LLINT num)
	{
		return operator+=(Fraction(num, 1));
	}

	Fraction operator +=(const Fraction& fraction)
	{
		LLINT denomLcm = LCM(_denom, fraction._denom);
		LLINT factor1 = denomLcm / _denom;
		LLINT factor2 = denomLcm / fraction._denom;

		_num = _num * factor1 + fraction._num * factor2;
		_denom = denomLcm;

		simplify();
		return *this;
	}

	Fraction operator -=(LLINT num)
	{
		return operator-=(Fraction(num, 1));
	}

	Fraction operator -=(const Fraction& fraction)
	{
		return operator+=(-fraction);
		/*_num = (_num * fraction._denom - fraction._num * _denom);
		_denom = _denom * fraction._denom;
		simplify();
		return *this;*/
	}

	Fraction operator *=(LLINT num)
	{
		return operator*=(Fraction(num, 1));
	}

	Fraction operator *=(Fraction fraction)
	{
		if ( (fraction == 0) || (*this == 0) )
		{
			_num = 0;
			_denom = 1;
		}
		else
		{
			LLINT rhsNum = fraction._num;
			LLINT rhsDenom = fraction._denom;
			LLINT hcf1 = HCF(_num, rhsDenom);
			LLINT hcf2 = HCF(_denom, rhsNum);

			_num /= hcf1;
			rhsDenom /= hcf1;

			_denom /= hcf2;
			rhsNum /= hcf2;

			_num *= rhsNum;
			_denom *= rhsDenom;
		}

		return *this;
	}

	Fraction operator /=(LLINT num)
	{
		if (0 == num)
			throw std::runtime_error("Attempt to divide by 0");
		else
			return operator/=(Fraction(num, 1));
	}

	Fraction operator /=(Fraction fraction)
	{
		if (fraction == 0)
			throw std::runtime_error("Attempt to divide by 0");
		else
			return operator *=(Fraction(fraction._denom, fraction._num));
	}

	Fraction operator +(LLINT num) const
	{
		return operator+(Fraction(num, 1));
		//LLINT newNum = _num + (num * _denom);
		//return Fraction(newNum, _denom);
	}

	Fraction operator +(const Fraction& fraction) const
	{
		LLINT denomLcm = LCM(_denom, fraction._denom);
		LLINT factor1 = denomLcm / _denom;
		LLINT factor2 = denomLcm / fraction._denom;

		LLINT newNum = _num * factor1 + fraction._num * factor2;
		return Fraction(newNum, denomLcm);
	}

	Fraction operator -(LLINT num) const
	{
		return operator-(Fraction(num, 1));
		//LLINT newNum = _num - (num * _denom);
		//return Fraction(newNum, _denom);
	}

	Fraction operator -(const Fraction& fraction) const
	{

		return operator+(-fraction);
		/*LLINT newNum = _num * fraction._denom - fraction._num * _denom;
		LLINT newDenom = _denom * fraction._denom;
		return Fraction(newNum, newDenom);*/
	}

	Fraction operator *(LLINT num)
	{
		return operator*(Fraction(num, 1));
	}

	Fraction operator *(Fraction fraction)
	{
		LLINT newNum;
		LLINT newDenom;
		if (fraction == 0)
		{
			newNum = 0;
			newDenom = 1;
		}
		else
		{
			LLINT rhsNum = fraction._num;
			LLINT rhsDenom = fraction._denom;
			LLINT hcf1 = HCF(_num, rhsDenom);
			LLINT hcf2 = HCF(_denom, rhsNum);

			newNum = (_num / hcf1) * (rhsNum / hcf2);
			newDenom = (_denom / hcf2) * (rhsDenom / hcf1);
		}

		return Fraction(newNum, newDenom);
	}

	Fraction operator /(LLINT num)
	{
		if (0 == num)
			throw std::runtime_error("Attempt to divide by 0");
		else
		{
			return operator/(Fraction(num, 1));
		}
	}

	Fraction operator /(Fraction fraction)
	{
		if (fraction == 0)
			throw std::runtime_error("Attempt to divide by 0");
		else
			return operator*(Fraction(fraction._denom, fraction._num));
	}

	Fraction operator -() const
	{
		return Fraction(-_num, _denom);
		/*LLINT newNum = _num * fraction._denom - fraction._num * _denom;
		LLINT newDenom = _denom * fraction._denom;
		return Fraction(newNum, newDenom);*/
	}
	bool operator ==(const Fraction& fraction) const
	{
		return ((_num == fraction._num) && (_denom == fraction._denom));
	}

	bool operator ==(LLINT num) const
	{
		return (operator==(Fraction(num, 1)));
	}

	bool operator !=(const Fraction& fraction) const
	{
		return !(operator==(fraction));
	}

	bool operator !=(LLINT num) const
	{
		return !(operator==(num));
	}

	bool operator<(LLINT num)
	{
		return operator<(Fraction(num,1));
	}

	bool operator<=(LLINT num)
	{
		return operator<=(Fraction(num, 1));
	}

	bool operator>(LLINT num)
	{
		return operator>(Fraction(num, 1));
	}

	bool operator>=(LLINT num)
	{
		return operator>=(Fraction(num, 1));
	}

	bool operator<(const Fraction& fraction)
	{
		LLINT lcm = LCM(_denom, fraction._denom);
	}

	bool operator<=(const Fraction& fraction)
	{
		return (operator<(fraction) || operator==(fraction));
	}

	bool operator>(const Fraction& fraction)
	{
		return !operator<=(fraction);
	}

	bool operator>=(const Fraction& fraction)
	{
		return !operator<(fraction);
	}
};
