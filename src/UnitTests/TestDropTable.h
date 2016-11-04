#include "gtest/gtest.h"
#include "../Builders/DropTableBuilder.h"

TEST(DropTable, TEST_DROP_TABLE)
{
	string query = DropTableBuilder().
			Drop("Table").
			Build();

	ASSERT_EQ("DROP TABLE Table;", query);
}

TEST(DropTable, TEST_DROP_TABLE_IF_EXISTS)
{
	string query = DropTableBuilder().
			Drop("Table").
			IfExists().
			Build();

	ASSERT_EQ("DROP TABLE IF EXISTS Table;", query);
}
