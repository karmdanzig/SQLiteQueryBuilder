#include "gtest/gtest.h"
#include "../Builders/SelectBuilder.h"

TEST(SelectClause, TEST_BASIC_SELECT)
{
	string query = SelectBuilder().
			Select("Column").
			From("Table").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table;", query);
}
/*
TEST(SelectClause, TEST_BASIC_SELECT_WITH_ALIAS)
{
    string query = SelectBuilder().
            Select("Column").
            FromAs("Table1", "T1").
            JoinAs("Table2", "T2").
            OnEqual("Column5", "T1", "T2").
            Build();

    ASSERT_EQ("SELECT Column\nFROM Table1 AS T1 JOIN Table2 AS T2 ON T1.Column5 = T2.Column5;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ALIAS_AND_TWO_CONDITIONS)
{
    string query = SelectBuilder().
            Select("Column").
            FromAs("Table1", "T1").
            JoinAs("Table2", "T2").
            OnEqual("Column5", "T1", "T2").
            And().
            OnEqual("Column3", "T1", "T2").
            Build();

    ASSERT_EQ("SELECT Column\nFROM Table1 AS T1 JOIN Table2 AS T2 ON T1.Column5 = T2.Column5 AND T1.Column3 = T2.Column3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_TWO_ALIAS_AND_TWO_CONDITIONS)
{
    string query = SelectBuilder().
            Select("Column").
            FromAs("Table1", "T1").
            JoinAs("Table2", "T2").
            JoinAs("Table3", "T3").
            OnEqual("Column1", "T1", "T2").
            And().
            OnEqual("Column2", "T2", "T3").
            Build();

    ASSERT_EQ("SELECT Column\nFROM Table1 AS T1 JOIN Table2 AS T2 JOIN Table3 AS T3 ON T1.Column1 = T2.Column1 AND T2.Column2 = T3.Column2;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_TWO_ALIAS_AND_TWO_CONDITIONS_WITH_WHERE_CLAUSE)
{
    string query = SelectBuilder().
            Select("Column").
            FromAs("Table1", "T1").
            JoinAs("Table2", "T2").
            JoinAs("Table3", "T3").
            OnEqual("Column1", "T1", "T2").
            And().
            OnEqual("Column2", "T2", "T3").
            WhereGreaterThan("Column3", 8).
            Or().
            WhereBetween("Column4", 10, 34).
            Build();

    ASSERT_EQ("SELECT Column\nFROM Table1 AS T1 JOIN Table2 AS T2 JOIN Table3 AS T3 ON T1.Column1 = T2.Column1 AND T2.Column2 = T3.Column2\nWHERE Column3 > 8 OR Column4 BETWEEN 10 AND 34;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_THREE_ALIAS_AND_THREE_CONDITIONS_WITH_WHERE_CLAUSE)
{
    string query = SelectBuilder().
            Select("Column").
            FromAs("Table1", "T1").
            JoinAs("Table2", "T2").
            JoinAs("Table3", "T3").
            OnEqual("Column1", "T1", "T2").
            And().
            OnEqual("Column2", "T2", "T3").
			Or().
			OnEqual("Column3", "T3", "T1").
            WhereGreaterThan("Column3", 8).
            Or().
            WhereBetween("Column4", 10, 34).
			And().
			WhereNotLike("Column4", "Ft%").
            Build();

    ASSERT_EQ("SELECT Column\nFROM Table1 AS T1 JOIN Table2 AS T2 JOIN Table3 AS T3 ON T1.Column1 = T2.Column1 AND T2.Column2 = T3.Column2 OR T3.Column3 = T1.Column3\nWHERE Column3 > 8 OR Column4 BETWEEN 10 AND 34 AND Column4 NOT LIKE 'Ft%';", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_NATURAL_JOIN)
{
	string query = SelectBuilder().
			Select("Column").
			From("Table").
			NaturalJoin("Table2").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table NATURAL JOIN Table2;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_CROSS_JOIN)
{
	string query = SelectBuilder().
			Select("Column").
			From("Table").
			CrossJoin("Table2").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table CROSS JOIN Table2;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_NATURAL_OUTER_JOIN)
{
	string query = SelectBuilder().
			Select("Column").
			From("Table").
			NaturalLeftOuterJoin("Table2").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table NATURAL LEFT OUTER JOIN Table2;", query);
}
*/
TEST(SelectClause, TEST_BASIC_SELECT_ALL)
{
	string query = SelectBuilder().
			SelectAll().
			From("Table").
			Build();

	ASSERT_EQ("SELECT *\nFROM Table;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_DISTINCT)
{
	string query = SelectBuilder().
			Select("Column").
			Distinct().
			From("Table").
			Build();

	ASSERT_EQ("SELECT DISTINCT Column\nFROM Table;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_DISTINCT_ALL)
{
	string query = SelectBuilder().
			SelectAll().
			Distinct().
			From("Table").
			Build();

	ASSERT_EQ("SELECT DISTINCT *\nFROM Table;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_INTEGER_CONDITION)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", 2).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = 2;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_WHERE_IN_WITH_ONE_ELEMENT)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereIn("Column1", 1, 10).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column1 IN (10);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_WHERE_IN_WITH_TWO_ELEMENTS)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereIn("Column1", 2, 1, 2).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column1 IN (1,2);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_WHERE_IN_WITH_FIVE_ELEMENTS)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereIn("Column1", 5, 1, 2, 3, 4, 5).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column1 IN (1,2,3,4,5);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_SUBQUERY)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereInQuery("Column", SelectBuilder().Select("Column2").From("Table2").Build()).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column IN (SELECT Column2\nFROM Table2);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_CONDITION)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\';", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_LIKE_CONDITION)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereLike("Column", "_T%").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column LIKE \'_T%\';", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_NOT_LIKE_CONDITION)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereNotLike("Column", "_T%").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column NOT LIKE \'_T%\';", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_AND_CLAUSE)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			And().
			WhereEqualOrLessThan("Column4", 3).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\' AND Column4 <= 3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_OR_CLAUSE)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			Or().
			WhereEqualOrLessThan("Column4", 3).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\' OR Column4 <= 3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_AND_OR_CLAUSE)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			And().
			WhereEqualOrLessThan("Column4", 3).
			Or().
			WhereEqualOrGreaterThan("Column5", 7).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\' AND Column4 <= 3 OR Column5 >= 7;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_BETWEEN_CLAUSE)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereBetween("Column2", 3, 4).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column2 BETWEEN 3 AND 4;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_NOT_BETWEEN_CLAUSE)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereNotBetween("Column2", 3, 4).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column2 NOT BETWEEN 3 AND 4;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_HAVING)
{
	string query = SelectBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			Having("Column2", 5).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3\nHAVING Column2 = 5;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY)
{
	string query = SelectBuilder().
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

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY_ASC)
{
	string query = SelectBuilder().
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

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3 ASC;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY_DESC)
{
	string query = SelectBuilder().
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

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3 DESC;", query);
}
