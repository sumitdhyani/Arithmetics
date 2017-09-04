// UnitTests.cpp : Defines the entry point for the console application.
//

#include <gtest/gtest.h>
#include "Fraction.h"

class FractionTest : public testing::Test
{
	Fraction * fraction;

	virtual void SetUp()
	{
		fraction  = new Fraction(2,3);
	}

	FractionTest(LLINT num, LLINT denom)
	{
		fraction = NULL;
	}
	
	~FractionTest()
	{
		try
		{
			delete fraction;
		}
		catch (...) {}
	}
};

TEST(BasicTest, Basic1)
{
	Fraction fraction( 2, 3 );
	EXPECT_EQ(Fraction( 2, 3), fraction);
}

TEST(BasicTest, Basic2)
{
	Fraction fraction(4, 6);
	EXPECT_EQ(Fraction(2, 3), fraction);
}

TEST(BasicTest, Basic3)
{
	Fraction fraction(6, 4);
	EXPECT_EQ(Fraction(3, 2), fraction);
}

TEST(BasicTest, Basic4)
{
	EXPECT_ANY_THROW(Fraction fraction(1, 0));
}

TEST(BasicTest, Basic5)
{
	Fraction fraction(0, 7);
	EXPECT_EQ(Fraction(0, 3), fraction);
}

TEST(BasicTest, Basic6)
{
	Fraction fraction(-2, 7);
	EXPECT_EQ(Fraction(2, -7), fraction);
}


TEST(Addition, AddInteger)
{
	Fraction fraction(2, 3);
	fraction += 5;
	EXPECT_EQ(Fraction(17, 3), fraction);

	fraction = Fraction(4, 6);
	fraction += 5;
	EXPECT_EQ(Fraction(17, 3), fraction);

	fraction = Fraction(4, 6);
	fraction += 0;
	EXPECT_EQ(Fraction(2, 3), fraction);

	fraction = Fraction(2, 3);
	fraction += -1;
	EXPECT_EQ(Fraction(-1, 3), fraction);

	fraction = Fraction(3, 2);
	fraction += -1;
	EXPECT_EQ(Fraction(1, 2), fraction);
}


TEST(Addition, AddFraction)
{
	Fraction fraction(-3, 5);
	fraction += Fraction(5, 3);
	EXPECT_EQ(Fraction(16, 15), fraction);

	fraction = Fraction(-3, 5);
	fraction += Fraction(6, 10);
	EXPECT_EQ(Fraction(0, 7), fraction);

	fraction = Fraction(10, -7);
	fraction += Fraction(11, 6);
	EXPECT_EQ(Fraction(34, 84), fraction);

	fraction = Fraction(7, 18);
	fraction += Fraction(9, 8);
	EXPECT_EQ(Fraction(109, 72), fraction);
}


TEST(AdditionOperator, AdditionOperatorInteger)
{
	Fraction fraction(2, 3);
	EXPECT_EQ(Fraction(17, 3), fraction + 5);

	fraction = Fraction(4, 6);
	EXPECT_EQ(Fraction(17, 3), fraction + 5);

	fraction = Fraction(4, 6);
	EXPECT_EQ(Fraction(2, 3), fraction + 0);

	fraction = Fraction(2, 3);
	EXPECT_EQ(Fraction(-1, 3), fraction + -1);

	fraction = Fraction(3, 2);
	EXPECT_EQ(Fraction(1, 2), fraction + -1);
}


TEST(Subtraction, SubtractInteger)
{
	Fraction fraction(19, 5);
	fraction -= 3;
	EXPECT_EQ(Fraction(4, 5), fraction);

	fraction= Fraction(57, 15);
	fraction -= 3;
	EXPECT_EQ(Fraction(4, 5), fraction);

	fraction = Fraction(4, 6);
	fraction -= 0;
	EXPECT_EQ(Fraction(2, 3), fraction);

	fraction = Fraction(2, 3);
	fraction -= -1;
	EXPECT_EQ(Fraction(5, 3), fraction);

	fraction = Fraction(-12, 8);
	fraction -= -5;
	EXPECT_EQ(Fraction(7, 2), fraction);
}

TEST(Subtraction, SubtractFraction)
{
	Fraction fraction(3, 5);
	fraction -= Fraction(5, 3);
	EXPECT_EQ(Fraction(-16, 15), fraction);

	fraction = Fraction(3, 5);
	fraction -= Fraction(6, 10);
	EXPECT_EQ(Fraction(0, 3), fraction);

	fraction = Fraction(10, -7);
	fraction -= Fraction(11, 6);
	EXPECT_EQ(Fraction(-137, 42), fraction);
}

TEST(SubtractionOperator, SubtractionOperatorInteger)
{
	Fraction fraction(19, 5);
	EXPECT_EQ(Fraction(4, 5), fraction - 3);

	fraction = Fraction(57, 15);
	EXPECT_EQ(Fraction(4, 5), fraction - 3);

	fraction = Fraction(4, 6);
	EXPECT_EQ(Fraction(2, 3), fraction - 0);

	fraction = Fraction(2, 3);
	EXPECT_EQ(Fraction(5, 3), fraction - (-1));

	fraction = Fraction(-12, 8);
	EXPECT_EQ(Fraction(7, 2), fraction - (-5));
}








TEST(MultiPlicationOperator, ByInteger)
{
	EXPECT_EQ(Fraction(3, 7) * -3, Fraction(-27, 21));
	EXPECT_EQ(Fraction(3, 7) * 0, 0);
	EXPECT_EQ(Fraction(3, 7) * 14, 6);
	EXPECT_EQ(Fraction(-3, 7) * 14, -6);
	EXPECT_EQ(Fraction(-3, 7) * -14, 6);
}

TEST(MultiPlicationOperator, ByFraction)
{
	EXPECT_EQ(Fraction(3, 7) * Fraction(0,1), 0);
	EXPECT_EQ(Fraction(3, 7) * Fraction(7, 3), 1);
	EXPECT_EQ(Fraction(12, 7) * Fraction(35, 21), Fraction(40, 14));
	EXPECT_EQ(Fraction(12, 7) * Fraction(-35, 21), Fraction(40,-14));
}


TEST(Division, ByInteger)
{
	EXPECT_EQ(Fraction(3, 7) / -3, Fraction(1, -7));
	EXPECT_ANY_THROW(Fraction(3, 7) / 0 == 0);
	EXPECT_EQ(Fraction(3, 7) / 14, Fraction(3, 98));
	EXPECT_EQ(Fraction(-3, 7) / 14, Fraction(-3, 98));
	EXPECT_EQ(Fraction(-3, 7) / -14, Fraction(3, 98));
}

TEST(Division, ByFraction)
{
	EXPECT_ANY_THROW(Fraction(3, 7) / Fraction(0, 1));
	EXPECT_EQ(Fraction(3, 7) / Fraction(3, 7), 1);
	EXPECT_EQ(Fraction(12, 7) / Fraction(21 , 35), Fraction(40, 14));
	EXPECT_EQ(Fraction(12, 7) / Fraction(21, -35), Fraction(40, -14));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
    return 0;
}
