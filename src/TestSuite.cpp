#include "gtest/gtest.h"
#include "DataBaseQueryBuilder.h"
#include "TestClauses/TestSelect.h"
#include "TestClauses/TestDelete.h"
#include "TestClauses/TestDrop.h"
#include "TestClauses/TestCreate.h"
#include "TestClauses/TestUpdate.h"
#include "TestClauses/TestInsert.h"
#include "TestClauses/TestAlter.h"
#include "TestClauses/TestPragma.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
