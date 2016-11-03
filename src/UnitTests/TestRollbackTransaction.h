#include "gtest/gtest.h"
#include "../Builders/RollbackTransactionBuilder.h"

TEST(RollbackTransactionClause, TEST_ROLLBACK_TRANSACTION)
{
    string query = RollbackTransactionBuilder().
            Rollback().
            Build();

    ASSERT_EQ("ROLLBACK;", query);
}
