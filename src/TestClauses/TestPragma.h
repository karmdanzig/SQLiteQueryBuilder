#include "gtest/gtest.h"
#include "../DataBaseQueryBuilder.h"

TEST(PragmaClause, TEST_PRAGMA_INTEGRITY_CHECK)
{
    string query = DataBaseQueryBuilder().
            PragmaIntegrityCheck().
            Build();

    ASSERT_EQ("PRAGMA integrity_check;", query);
}

TEST(PragmaClause, TEST_PRAGMA_TABLE_INFO)
{
    string query = DataBaseQueryBuilder().
            PragmaTableInfo("Table").
            Build();

    ASSERT_EQ("PRAGMA table_info(Table);", query);
}
