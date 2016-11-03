#include "gtest/gtest.h"
#include "../Builders/EndTransactionBuilder.h"

TEST(EndTransactionClause, TEST_END_TRANSACTION)
{
	string query = EndTransactionBuilder().
			End("MyTransaction").
			Build();

	ASSERT_EQ("END MyTransaction;", query);
}
