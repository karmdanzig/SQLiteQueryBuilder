#include "gtest/gtest.h"
#include "../Builders/AlterBuilder.h"

TEST(Alter, TEST_ALTER_RENAME)
{
	string query = AlterBuilder().
			Alter("Table").
			RenameTo("Table1").
			Build();

	ASSERT_EQ("ALTER Table RENAME TO Table1;", query);
}

TEST(Alter, TEST_ALTER_ADD_COLUMN)
{
	string query = AlterBuilder().
			Alter("Table").
			AddColumn("Field1", "INT", true, true).
			Build();

	ASSERT_EQ("ALTER Table ADD COLUMN Field1 INT PRIMARY KEY NOT NULL;", query);
}
