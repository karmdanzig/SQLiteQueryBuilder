#include "gtest/gtest.h"
#include "DataBaseQueryBuilder.h"

TEST(UpdateClause, TEST_UPDATE_TABLE)
{
	string query = DataBaseQueryBuilder().
			Update("Table").
			Set("Column1", "2").
			Set("Column2", 3).
			Build();

	ASSERT_EQ("UPDATE Table\nSET Column1 = \'2\', Column2 = 3;", query);
}

TEST(UpdateClause, TEST_UPDATE_TABLE_WITH_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Update("Table").
			Set("Column1", "2").
			Set("Column2", 3).
			WhereLessThan("Column3", 4).
			Build();

	ASSERT_EQ("UPDATE Table\nSET Column1 = \'2\', Column2 = 3\nWHERE Column3 < 4;", query);
}
