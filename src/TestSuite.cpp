#include "gtest/gtest.h"

#include "UnitTests/TestSelect.h"
#include "UnitTests/TestBeginTransaction.h"
#include "UnitTests/TestDelete.h"
#include "UnitTests/TestAlter.h"
#include "UnitTests/TestUpdate.h"
#include "UnitTests/TestCreate.h"
#include "UnitTests/TestCreateIndex.h"
#include "UnitTests/TestInsert.h"
#include "UnitTests/TestDrop.h"
#include "UnitTests/TestPragma.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

