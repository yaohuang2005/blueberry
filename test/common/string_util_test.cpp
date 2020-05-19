//
// Created by Yao Huang on 2020-05-19.
//
#include "common/util/string_util.h"

#include "gtest/gtest.h"
#include <string>

using namespace blueberry;

namespace {
    TEST(StringUtil_Tests, ContainTest) {
        std::string haystack{"helloworld"};
        std::string needle{"world"};
        bool contained = StringUtil::Contains(haystack, needle);

        EXPECT_EQ(contained, true);
    }
}