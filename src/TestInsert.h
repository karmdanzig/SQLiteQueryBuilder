#include "gtest/gtest.h"
#include "DataBaseQueryBuilder.h"

TEST(InsertClause, TEST_INSERT_INTO_TABLE)
{
	string query = DataBaseQueryBuilder().
			InsertInto("Table").
			Values("SomeText").
			Values("2").
			Values(3).
			Build();

	ASSERT_EQ("INSERT INTO Table\nVALUES (\'SomeText\', \'2\', 3);", query);
}