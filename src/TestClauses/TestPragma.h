#include "gtest/gtest.h"
#include "../DataBaseQueryBuilder.h"

TEST(PragmaClause, TEST_PRAGMA)
{
    string query = DataBaseQueryBuilder().
            PragmaIntegrityCheck().
            Build();

    ASSERT_EQ("PRAGMA integrity_check;", query);
}
