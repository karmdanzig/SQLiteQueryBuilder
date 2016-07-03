#include "gtest/gtest.h"
#include "DataBaseQueryBuilder.h"

using namespace std;

TEST(SelectClause, TEST_BASIC_SELECT)
{
	string query = DataBaseQueryBuilder().
			Select("Column").
			From("Table").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_INTEGER_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", 2).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = 2);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\');", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_LIKE_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereLike("Column", "_T%").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column LIKE \'_T%\');", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_AND_CLAUSE)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			And().
			WhereEqualOrLessThan("Column4", 3).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\' AND Column4 <= 3);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_OR_CLAUSE)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			Or().
			WhereEqualOrLessThan("Column4", 3).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\' OR Column4 <= 3);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_AND_OR_CLAUSE)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			And().
			WhereEqualOrLessThan("Column4", 3).
			Or().
			WhereEqualOrGreaterThan("Column5", 7).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\' AND Column4 <= 3 OR Column5 >= 7);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\')\nGROUP BY Column1, Column2, Column3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			OrderBy("Column1").
			OrderBy("Column2").
			OrderBy("Column3").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\')\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY_ASC)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			OrderBy("Column1").
			OrderBy("Column2").
			OrderBy("Column3").
			Asc().
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\')\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3 ASC;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY_DESC)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			OrderBy("Column1").
			OrderBy("Column2").
			OrderBy("Column3").
			Desc().
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE (Column = \'2\')\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3 DESC;", query);
}

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

	ASSERT_EQ("DELETE FROM Table\nWHERE (Column = \'2\');", query);
}

TEST(DropClause, TEST_DROP_TABLE)
{
	string query = DataBaseQueryBuilder().
			DropTable("Table").
			Build();

	ASSERT_EQ("DROP TABLE Table;", query);
}

TEST(CreateClause, TEST_CREATE_TABLE)
{
	string query = DataBaseQueryBuilder().
			CreateTable("Table").
			Field("Field1", "INT", true, true).
			Field("Field2", "CHAR(50)", false, true).
			Build();

	ASSERT_EQ("CREATE TABLE Table (\nField1 INT PRIMARY KEY NOT NULL,\nField2 CHAR(50) NOT NULL);", query);
}

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

	ASSERT_EQ("UPDATE Table\nSET Column1 = \'2\', Column2 = 3\nWHERE (Column3 < 4);", query);
}

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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
