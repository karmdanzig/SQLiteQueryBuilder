#include "gtest/gtest.h"
#include "../Builders/DropIndexBuilder.h"

TEST(DropIndex, TEST_DROP_INDEX)
{
	string query = DropIndexBuilder().
			DropIndex("MyIndex").
			Build();

	ASSERT_EQ("DROP INDEX MyIndex;", query);
}

TEST(DropIndex, TEST_DROP_INDEX_IF_EXISTS)
{
	string query = DropIndexBuilder().
	        DropIndex("MyIndex").
			IfExists().
			Build();

	ASSERT_EQ("DROP INDEX IF EXISTS MyIndex;", query);
}
