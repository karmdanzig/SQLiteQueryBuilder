#ifndef SRC_DATABASEQUERYBUILDER_H_
#define SRC_DATABASEQUERYBUILDER_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DataBaseQueryBuilder
{
public:

    DataBaseQueryBuilder ();

    ~DataBaseQueryBuilder ();

    string Build();

    DataBaseQueryBuilder& Select(string ColumnToSelect);

    DataBaseQueryBuilder& SelectAll();

    DataBaseQueryBuilder& From(string fromClause);

    DataBaseQueryBuilder& Update(string TableToUpdate);

    DataBaseQueryBuilder& Delete();

    DataBaseQueryBuilder& InsertInto(string table);

    DataBaseQueryBuilder& CreateTable(string table);

    DataBaseQueryBuilder& Field(string fieldName, string fieldType, bool primaryKey, bool notNull);

    DataBaseQueryBuilder& DropTable(string table);

    DataBaseQueryBuilder& Set(string setField, string value);

    DataBaseQueryBuilder& Set(string setField, int value);

    DataBaseQueryBuilder& Values(string value);

    DataBaseQueryBuilder& Values(int value);

    DataBaseQueryBuilder& WhereEqual(string FilterField, string value);

    DataBaseQueryBuilder& WhereLessThan(string FilterField, string value);

    DataBaseQueryBuilder& WhereGreaterThan(string FilterField, string value);

    DataBaseQueryBuilder& WhereEqualOrLessThan(string FilterField, string value);

    DataBaseQueryBuilder& WhereEqualOrGreaterThan(string FilterField, string value);

    DataBaseQueryBuilder& WhereEqual(string FilterField, int value);

    DataBaseQueryBuilder& WhereLessThan(string FilterField, int value);

    DataBaseQueryBuilder& WhereGreaterThan(string FilterField, int value);

    DataBaseQueryBuilder& WhereEqualOrLessThan(string FilterField, int value);

    DataBaseQueryBuilder& WhereEqualOrGreaterThan(string FilterField, int value);

    DataBaseQueryBuilder& WhereLike(string FilterField, string value);

    DataBaseQueryBuilder& WhereLike(string FilterField, int value);

    DataBaseQueryBuilder& And();

    DataBaseQueryBuilder& Or();

    DataBaseQueryBuilder& GroupBy(string column);

    DataBaseQueryBuilder& OrderBy(string column);

    DataBaseQueryBuilder& Asc();

    DataBaseQueryBuilder& Desc();

    DataBaseQueryBuilder& Distinct();

    DataBaseQueryBuilder& Having(string FilterField, string value);

    DataBaseQueryBuilder& Having(string FilterField, int value);

    DataBaseQueryBuilder& WhereIn(string FilterField, string query);

private:
    string m_finalString;

    vector<string> m_selectList;
    vector<string> m_fieldsList;
    vector<string> m_whereList;
    vector<string> m_setList;
    vector<string> m_valuesList;
    vector<string> m_operatorList;
    vector<string> m_groupbyList;
    vector<string> m_orderbyList;
    vector<string> m_havingList;
    string m_from;
    string m_update;
    string m_insertInto;
    string m_createTable;
    string m_dropTable;
    bool m_delete;
    bool m_asc;
    bool m_desc;
    bool m_selectAll;
    int m_queryType;
    bool m_distinct;

    void addReturnLine();
    void processSelectClause();
    void processFromClause();
    void processWhereClause();
    void processGroupByClause();
    void processOrderByClause();
    void processDeleteClause();
    void processInsertIntoClause();
    void processValuesClause();
    void processUpdateClause();
    void processSetClause();
    void processCreateClause();
    void processTableFields();
    void processDropClause();
    void processHavingClause();

    void insertFromListWithSeparator(vector<string>& whichlist, string separator);
};

#endif /* SRC_DATABASEQUERYBUILDER_H_ */
