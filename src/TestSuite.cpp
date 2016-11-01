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
#include "Builders/DropBuilder.h"
#include "Builders/InsertBuilder.h"
#include "Builders/CreateBuilder.h"
#include "Builders/UpdateBuilder.h"
#include "Builders/CreateIndexBuilder.h"
#include "Builders/BeginTransactionBuilder.h"
#include "Builders/EndTransactionBuilder.h"
#include "Builders/RollbackTransactionBuilder.h"

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
            GroupBy("Column2").
            Having("Column5", 1).
            OrderBy("Column3").
            OrderBy("Column4").
            Asc().
            Build();
    std::cout << r << std::endl;

    r = PragmaBuilder().
            PragmaVdbeTrace().
            Build();
    std::cout << r << std::endl;

    r = AlterBuilder().
            Alter("Table2").
            RenameTo("Table3").
            Build();
    std::cout << r << std::endl;

    r = AlterBuilder().
            Alter("Table2").
            AddColumn("Column2", "INT", 0, 1).
            Build();
    std::cout << r << std::endl;


    r = InsertBuilder().
            InsertInto("Table2").
            Values(3).
            Values(4).
            Build();
    std::cout << r << std::endl;

    r = CreateBuilder().
            Create("Table2").
            Field("Column2", "INT", true, true).
            Field("Column3", "VAR", true, false).
            Build();
    std::cout << r << std::endl;

    r = UpdateBuilder().
            Update("Table").
            Set("Column1", "2").
            Set("Column2", 3).
            WhereLessThan("Column3", 4).
            Build();
    std::cout << r << std::endl;

    r = CreateIndexBuilder().
            CreateUniqueIndex("Index").
            IfNotExists().
            OnTable("Table2").
            Columns("Column1").
            Columns("Column2").
            Columns("Column3").
            Build();

    std::cout << r << std::endl;

    r = BeginTransactionBuilder().
            Begin("Transaction").
            Build();

    std::cout << r << std::endl;

    r = EndTransactionBuilder().
            End("Transaction").
            Build();

    std::cout << r << std::endl;

    r = RollbackTransactionBuilder().
            Rollback().
            Build();

    std::cout << r << std::endl;

    /*
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}
