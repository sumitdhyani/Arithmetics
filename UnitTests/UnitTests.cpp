// UnitTests.cpp : Defines the entry point for the console application.
//

#include <gtest/gtest.h>
#include "Fraction.h"
#include "BigInt.h"

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

#define TEST_RELATIONAL_OPERATOR_INEQUALITY(TestName, Operator, trueNess, falseNess)\

#define TEST_RELATIONAL_OPERATOR_INEQUALITY(TestName, Operator, trueNess, falseNess)\
TEST(RelationalOperators, TestName)						\
{														\
	trueNess(Fraction(4, 5) Operator Fraction(5, 6));	\
	falseNess(Fraction(5, 6) Operator Fraction(4, 5));	\
														\
	trueNess(Fraction(-2, 5) Operator Fraction(0, -2));	\
	falseNess(Fraction(0, 5) Operator Fraction(-2, 5));	\
														\
	trueNess(Fraction(-8, 7) Operator Fraction(5, 6));	\
	falseNess(Fraction(5, 6) Operator Fraction(-8, 7));	\
														\
	trueNess(Fraction(-8, 7) Operator Fraction(-5, 6));\
	falseNess(Fraction(-5, 6) Operator Fraction(-8, 7));\
														\
	trueNess(0 Operator Fraction(5, 6));				\
	falseNess(Fraction(5, 6) Operator 0);				\
														\
	trueNess(Fraction(4, 5) Operator 1);				\
	falseNess(1 Operator Fraction(4, 5));				\
														\
	trueNess(-1 Operator Fraction(-5, 6));				\
	falseNess(Fraction(-5, 6) Operator -1);				\
														\
	trueNess(1 Operator Fraction(11, 3));				\
	trueNess(-2 Operator Fraction(11, 3));				\
	trueNess(0 Operator Fraction(11, 3));				\
														\
	falseNess(Fraction(11, 3) Operator 1);				\
	falseNess(Fraction(11, 3) Operator -2);				\
	falseNess(Fraction(11, 3) Operator 0);				\
}


TEST_RELATIONAL_OPERATOR_INEQUALITY(LessThan, <, EXPECT_TRUE, EXPECT_FALSE)
TEST_RELATIONAL_OPERATOR_INEQUALITY(GreaterThan, >, EXPECT_FALSE, EXPECT_TRUE)
TEST_RELATIONAL_OPERATOR_INEQUALITY(GreaterThanOrEqualTo, >=,EXPECT_FALSE, EXPECT_TRUE)

TEST(BigInt, AdditionPositiveNumbers)
{
	EXPECT_TRUE(add("10", "1") == "11");
	EXPECT_EQ(add("9", "1"), "10");
	EXPECT_EQ(add("99", "1"), "100");
	EXPECT_EQ(add("98", "7"), "105");
	EXPECT_EQ(add("55", "43"), "98");
	EXPECT_EQ(add("999999999999999999999999999","999999999999999999999999999"), "1999999999999999999999999998");
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
    return 0;
}
