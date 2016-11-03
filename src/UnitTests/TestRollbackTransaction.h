#include "gtest/gtest.h"
#include "../Builders/RollbackTransactionBuilder.h"

TEST(RollbackTransaction, TEST_ROLLBACK_TRANSACTION)
{
    string query = RollbackTransactionBuilder().
            Rollback().
            Build();

    ASSERT_EQ("ROLLBACK;", query);
}
