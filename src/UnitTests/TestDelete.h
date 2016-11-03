#include "gtest/gtest.h"
#include "../Builders/DeleteBuilder.h"

TEST(Delete, TEST_DELETE)
{
	string query = DeleteBuilder().
			Delete().
			From("Table").
			Build();

	ASSERT_EQ("DELETE\nFROM Table;", query);
}

TEST(Delete, TEST_DELETE_WITH_CONDITION)
{
	string query = DeleteBuilder().
			Delete().
			From("Table").
			WhereEqual("Column", "2").
			Build();

	ASSERT_EQ("DELETE\nFROM Table\nWHERE Column = \'2\';", query);
}
