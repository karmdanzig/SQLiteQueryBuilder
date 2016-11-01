#include "gtest/gtest.h"
#include "../Builders/DropBuilder.h"

TEST(DropClause, TEST_DROP_TABLE)
{
	string query = DropBuilder().
			Drop("Table").
			Build();

	ASSERT_EQ("DROP TABLE Table;", query);
}

TEST(DropClause, TEST_DROP_TABLE_IF_EXISTS)
{
	string query = DropBuilder().
			Drop("Table").
			IfExists().
			Build();

	ASSERT_EQ("DROP TABLE IF EXISTS Table;", query);
}
