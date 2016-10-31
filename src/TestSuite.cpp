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
#include "Builders/DeleteBuilder.h"
#include "Builders/PragmaBuilder.h"
#include "Builders/AlterBuilder.h"

#include <iostream>

int main(int argc, char **argv) {

    std::string r = DeleteBuilder().
            Delete().
            From("Table").
            WhereEqual("Column1", 3).
            Build();

    std::cout << r << std::endl;

    r = SelectBuilder().
                Select("Column7").
                From("Table").
                WhereEqual("Column1", 3).
                Build();

    std::cout << r << std::endl;

    r = PragmaBuilder().
            PragmaVdbeTrace().
                    Build();
    std::cout << r << std::endl;

    r = AlterBuilder().
            Alter("Table2").RenameTo("Table3").
                    Build();
    std::cout << r << std::endl;

    r = AlterBuilder().
            Alter("Table2").AddColumn("Column2", "INT", 0, 1).
                    Build();
    std::cout << r << std::endl;


    /*
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}
