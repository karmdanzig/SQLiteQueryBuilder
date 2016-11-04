#include "gtest/gtest.h"
#include "../Builders/DropTriggerBuilder.h"

TEST(DropTrigger, TEST_DROP_TRIGGER)
{
	string query = DropTriggerBuilder().
			DropTrigger("Trigger").
			Build();

	ASSERT_EQ("DROP TRIGGER Trigger;", query);
}

TEST(DropTrigger, TEST_DROP_TRIGGER_IF_EXISTS)
{
	string query = DropTriggerBuilder().
	        DropTrigger("Trigger").
			IfExists().
			Build();

	ASSERT_EQ("DROP TRIGGER IF EXISTS Trigger;", query);
}

