set (CMAKE_CXX_FLAGS "--std=gnu++14 ${CMAKE_CXX_FLAGS}")
include_directories(../ /cygdrive/c/gTest/googletest/include)
link_directories(cygdrive/c/gTest/googletest/lib/release)

add_executable(UnitTests
				UnitTests.cpp
				)

target_link_libraries(UnitTests "GTest.lib")
