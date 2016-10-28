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

#include "Keywords/Select.h"
#include "Keywords/From.h"
#include "Keywords/Where.h"
#include "Keywords/Keyword.h"

int main(int argc, char **argv) {

    vector<string> select;
    select.push_back("Column2");
    select.push_back("Column3");
    select.push_back("Column4");
    select.push_back("Column1");

    vector<string> where;
    where.push_back("Column2 = 0");
    where.push_back("Column3 < 8");

    queue<string> operators;
    operators.push("AND");


    Keyword *t = new Select(select);
    Keyword *f = new From("Table1");
    Keyword *e = new Where(where, operators);

    string r = t->getCompleteKeyword() + f->getCompleteKeyword() + e->getCompleteKeyword();

    cout << r << endl;

    /*
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}
