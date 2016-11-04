#include "gtest/gtest.h"
#include "../Builders/DropViewBuilder.h"

TEST(DropView, TEST_DROP_VIEW)
{
	string query = DropViewBuilder().
	        DropView("View").
			Build();

	ASSERT_EQ("DROP VIEW View;", query);
}

TEST(DropView, TEST_DROP_VIEW_IF_EXISTS)
{
	string query = DropViewBuilder().
	        DropView("View").
			IfExists().
			Build();

	ASSERT_EQ("DROP VIEW IF EXISTS View;", query);
}
