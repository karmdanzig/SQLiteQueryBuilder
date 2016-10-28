#include "gtest/gtest.h"
/*#include "DataBaseQueryBuilder.h"
#include "UnitTests/TestSelect.h"
#include "UnitTests/TestDelete.h"
#include "UnitTests/TestDrop.h"
#include "UnitTests/TestCreate.h"
#include "UnitTests/TestUpdate.h"
#include "UnitTests/TestInsert.h"
#include "UnitTests/TestAlter.h"
#include "UnitTests/TestPragma.h"*/

#include "Builders/SelectBuilder.h"


int main(int argc, char **argv) {

    string r = SelectBuilder().
            Select("Char1").
            Select("Char2").
            From("Table").
            Build();

    cout << r << endl;

    /*
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}
