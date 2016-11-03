#include "gtest/gtest.h"
#include "../Builders/BeginTransactionBuilder.h"

TEST(BeginTransaction, TEST_BEGIN_TRANSACTION_WITH_NO_NAME)
{
	string query = BeginTransactionBuilder().
			Begin().
			Build();

	ASSERT_EQ("BEGIN;", query);
}

TEST(BeginTransaction, TEST_BEGIN_TRANSACTION_WITH_NAME)
{
	string query = BeginTransactionBuilder().
	        Begin("MyTransaction").
			Build();

	ASSERT_EQ("BEGIN MyTransaction;", query);
}
