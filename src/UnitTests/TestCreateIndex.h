#include "gtest/gtest.h"
#include "../Builders/CreateIndexBuilder.h"

TEST(CreateIndexClause, TEST_CREATE_INDEX)
{
	string query = CreateIndexBuilder().
			CreateIndex("MyIndex").
			OnTable("MyTable").
			Columns("Column1").
			Build();

	ASSERT_EQ("CREATE INDEX MyIndex ON MyTable (Column1);", query);
}

TEST(CreateIndexClause, TEST_CREATE_INDEX_MULTIPLE_COLUMNS)
{
    string query = CreateIndexBuilder().
            CreateIndex("MyIndex").
            OnTable("MyTable").
            Columns("Column1").
            Columns("Column2").
            Build();

    ASSERT_EQ("CREATE INDEX MyIndex ON MyTable (Column1, Column2);", query);
}

TEST(CreateIndexClause, TEST_CREATE_UNIQUE_INDEX_IF_NOT_EXISTS_MULTIPLE_COLUMNS)
{
    string query = CreateIndexBuilder().
            CreateUniqueIndex("MyIndex").
            IfNotExists().
            OnTable("MyTable").
            Columns("Column1").
            Columns("Column2").
            Build();

    ASSERT_EQ("CREATE UNIQUE INDEX IF NOT EXISTS MyIndex ON MyTable (Column1, Column2);", query);
}
