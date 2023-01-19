#include "../../../src/lib/random/Random.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(RandomStringTest, GenerationTesting)
{
	auto res = RandomString(16);
	ASSERT_EQ(res.length(), 16);
	EXPECT_TRUE(testing::internal::RE::FullMatch(res, "^[a-z]{16}$"));
}