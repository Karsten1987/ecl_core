/**
 * @file /src/test/references.cpp
 *
 * @brief Unit Test for reference wrappers and associated tools.
 *
 * @date July 2009
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <gtest/gtest.h>
#include "../../include/ecl/utilities/references.hpp"

/**
 * @cond DO_NOT_DOXYGEN
 */

/*****************************************************************************
** Classes
*****************************************************************************/

namespace ecl {
namespace utilities {
namespace tests {

class ReferenceDummy {
public:
	int i;
};

}}}

/*****************************************************************************
** Using
*****************************************************************************/

using ecl::ReferenceWrapper;
using ecl::cref;
using ecl::ref;
using ecl::is_reference_wrapper;
using ecl::utilities::tests::ReferenceDummy;

/*****************************************************************************
** Tests
*****************************************************************************/

TEST(Reference,usage) {

    int i = 3;
    ReferenceWrapper<int> wrapper(i);
    int &j = wrapper;
    EXPECT_EQ(j,3);
}

TEST(Reference,traits) {
    // Workaround for undefined reference error. Why it happens if used
    // directly in the gtest macros, I haven't root caused.
    bool result1 = is_reference_wrapper< ReferenceWrapper<int> >::value;
	EXPECT_TRUE(result1);
    bool result2 = is_reference_wrapper<int>::value;
	EXPECT_FALSE(result2);
}

TEST(Reference,functions) {
    int i = 3;
    ReferenceWrapper<int> refd = ref(i);
    ReferenceWrapper<int const> crefd = cref(i);
    EXPECT_EQ(3,refd);
    EXPECT_EQ(3,crefd);
}

/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

/**
 * @endcond
 */

