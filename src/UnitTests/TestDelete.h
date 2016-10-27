#include "gtest/gtest.h"
#include "../DataBaseQueryBuilder.h"

TEST(DeleteClause, TEST_DELETE)
{
	string query = DataBaseQueryBuilder().
			Delete().
			From("Table").
			Build();

	ASSERT_EQ("DELETE FROM Table;", query);
}

TEST(DeleteClause, TEST_DELETE_WITH_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Delete().
			From("Table").
			WhereEqual("Column", "2").
			Build();

	ASSERT_EQ("DELETE FROM Table\nWHERE Column = \'2\';", query);
}
