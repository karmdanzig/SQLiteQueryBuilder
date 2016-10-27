#include "gtest/gtest.h"
#include "../DataBaseQueryBuilder.h"

TEST(CreateClause, TEST_CREATE_TABLE)
{
	string query = DataBaseQueryBuilder().
			Create("Table").
			Field("Field1", "INT", true, true).
			Field("Field2", "CHAR(50)", false, true).
			Build();

	ASSERT_EQ("CREATE TABLE Table (\nField1 INT PRIMARY KEY NOT NULL,\nField2 CHAR(50) NOT NULL);", query);
}

TEST(CreateClause, TEST_CREATE_TABLE_IF_NOT_EXISTS)
{
	string query = DataBaseQueryBuilder().
			Create("Table").
			IfNotExists().
			Field("Field1", "INT", true, true).
			Field("Field2", "CHAR(50)", false, true).
			Build();

	ASSERT_EQ("CREATE TABLE IF NOT EXISTS Table (\nField1 INT PRIMARY KEY NOT NULL,\nField2 CHAR(50) NOT NULL);", query);
}

TEST(CreateClause, TEST_CREATE_TEMPORARY_TABLE_IF_NOT_EXISTS)
{
	string query = DataBaseQueryBuilder().
			Create("Table").
			Temporary().
			IfNotExists().
			Field("Field1", "INT", true, true).
			Field("Field2", "CHAR(50)", false, true).
			Build();

	ASSERT_EQ("CREATE TEMPORARY TABLE IF NOT EXISTS Table (\nField1 INT PRIMARY KEY NOT NULL,\nField2 CHAR(50) NOT NULL);", query);
}
