/*
 * DataBaseQueryBuilder.h
 *
 *  Created on: 1 Jul 2016
 *      Author: carmelo
 */

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

    DataBaseQueryBuilder& And();

    DataBaseQueryBuilder& Or();

private:
    string m_finalString;

    vector<string> m_selectList;
    string m_from;
    vector<string> m_whereList;
    vector<string> m_setList;
    vector<string> m_valuesList;
    string m_update;
    string m_insertInto;
    string m_createTable;
    vector<string> m_fieldsList;
    string m_dropTable;
    bool m_delete;
    vector<string> m_operatorList;

    void processSelectClause();
    void processFromClause();
    void processWhereClause();
};

#endif /* SRC_DATABASEQUERYBUILDER_H_ */
