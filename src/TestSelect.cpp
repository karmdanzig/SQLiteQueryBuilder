#include "gtest/gtest.h"
#include <iostream>
#include "DataBaseQueryBuilder.h"

using namespace std;

TEST(SelectClause, TEST_BASIC_SELECT)
{
	string t = DataBaseQueryBuilder().
			Select("Column").
			From("Table").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table;", t);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_INTEGER_CONDITION)
{
	string t = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", 2).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = 2);", t);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_CONDITION)
{
	string t = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\');", t);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS)
{
	string t = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			WhereEqualOrLessThan("Column4", 3).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\' AND Column4 <= 3);", t);
}

TEST(DeleteClause, TEST_DELETE)
{
	string t = DataBaseQueryBuilder().
			Delete().
			From("Table").
			Build();

	ASSERT_EQ("DELETE FROM Table;", t);
}

TEST(DeleteClause, TEST_DELETE_WITH_CONDITION)
{
	string t = DataBaseQueryBuilder().
			Delete().
			From("Table").
			WhereEqual("Column", "2").
			Build();

	ASSERT_EQ("DELETE FROM Table\nWHERE (Column = \'2\');", t);
}

TEST(DropClause, TEST_DROP_TABLE)
{
	string t = DataBaseQueryBuilder().
			DropTable("Table").
			Build();

	ASSERT_EQ("DROP TABLE Table;", t);
}

TEST(CreateClause, TEST_CREATE_TABLE)
{
	string t = DataBaseQueryBuilder().
			CreateTable("Table").
			Field("Field1", "INT", true, true).
			Field("Field2", "CHAR(50)", false, true).
			Build();

	ASSERT_EQ("CREATE TABLE Table (\nField1 INT PRIMARY KEY NOT NULL,\nField2 CHAR(50) NOT NULL);", t);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
