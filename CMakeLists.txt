project("ArithmeticUtils")
set (CMAKE_CXX_FLAGS "--std=gnu++14 ${CMAKE_CXX_FLAGS}")
add_library(Arithmetiils STATIC
		 Fraction.cpp
		 BigInt.cpp
		 )
