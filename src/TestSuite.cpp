#include "gtest/gtest.h"
#include "DataBaseQueryBuilder.h"
#include "TestSelect.h"
#include "TestDelete.h"
#include "TestDrop.h"
#include "TestCreate.h"
#include "TestUpdate.h"
#include "TestInsert.h"
#include "TestAlter.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
