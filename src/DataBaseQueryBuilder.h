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

    DataBaseQueryBuilder& Select(const string ColumnToSelect);

    DataBaseQueryBuilder& SelectAll();

    DataBaseQueryBuilder& From(const string fromClause);

    DataBaseQueryBuilder& FromAs(const string table, const string alias);

    DataBaseQueryBuilder& JoinAs(const string table, const string alias);

    DataBaseQueryBuilder& OnEqual(const string column, const string alias1, const string alias2);

    DataBaseQueryBuilder& NaturalJoin(const string table);

    DataBaseQueryBuilder& CrossJoin(const string table);

    DataBaseQueryBuilder& NaturalLeftOuterJoin(const string table);

    DataBaseQueryBuilder& Update(const string TableToUpdate);

    DataBaseQueryBuilder& Delete();

    DataBaseQueryBuilder& InsertInto(const string table);

    DataBaseQueryBuilder& Create(const string table);

    DataBaseQueryBuilder& Field(const string fieldName, const string fieldType, const bool primaryKey, const bool notNull);

    DataBaseQueryBuilder& Drop(const string table);

    DataBaseQueryBuilder& Alter(const string table);

    DataBaseQueryBuilder& RenameTo(const string table);

    DataBaseQueryBuilder& Set(const string setField, const string value);

    DataBaseQueryBuilder& Set(const string setField, const int value);

    DataBaseQueryBuilder& Values(const string value);

    DataBaseQueryBuilder& Values(const int value);

    DataBaseQueryBuilder& WhereEqual(const string FilterField, const string value);

    DataBaseQueryBuilder& WhereLessThan(const string FilterField, const string value);

    DataBaseQueryBuilder& WhereGreaterThan(const string FilterField, const string value);

    DataBaseQueryBuilder& WhereEqualOrLessThan(const string FilterField, const string value);

    DataBaseQueryBuilder& WhereEqualOrGreaterThan(const string FilterField, const string value);

    DataBaseQueryBuilder& WhereEqual(const string FilterField, int value);

    DataBaseQueryBuilder& WhereLessThan(const string FilterField, int value);

    DataBaseQueryBuilder& WhereGreaterThan(const string FilterField, int value);

    DataBaseQueryBuilder& WhereEqualOrLessThan(const string FilterField, int value);

    DataBaseQueryBuilder& WhereEqualOrGreaterThan(const string FilterField, int value);

    DataBaseQueryBuilder& WhereLike(const string FilterField, const string value);

    DataBaseQueryBuilder& WhereLike(const string FilterField, const int value);

    DataBaseQueryBuilder& WhereNotLike(const string FilterField, const string value);

    DataBaseQueryBuilder& WhereNotLike(const string FilterField, const int value);

    DataBaseQueryBuilder& And();

    DataBaseQueryBuilder& Or();

    DataBaseQueryBuilder& GroupBy(const string column);

    DataBaseQueryBuilder& OrderBy(const string column);

    DataBaseQueryBuilder& Asc();

    DataBaseQueryBuilder& Desc();

    DataBaseQueryBuilder& Distinct();

    DataBaseQueryBuilder& Having(const string FilterField, const string value);

    DataBaseQueryBuilder& Having(const string FilterField, const int value);

    DataBaseQueryBuilder& WhereInQuery(const string FilterField, const string query);

    DataBaseQueryBuilder& WhereIn (const string FilterField, const int numberOfArguments, ... );

    DataBaseQueryBuilder& WhereBetween(const string FilterField, const int min, const int max);

    DataBaseQueryBuilder& WhereBetween(const string FilterField, const string min, const string max);

    DataBaseQueryBuilder& WhereNotBetween(const string FilterField, const int min, const int max);

    DataBaseQueryBuilder& WhereNotBetween(const string FilterField, const string min, const string max);

    DataBaseQueryBuilder& IfExists();

    DataBaseQueryBuilder& IfNotExists();

    DataBaseQueryBuilder& Temporary();

    DataBaseQueryBuilder& AddColumn(const string fieldName, const string fieldType, const bool primaryKey, const bool notNull);

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
    vector<string> m_fromAsList;
    vector<string> m_OnList;
    string m_from;
    string m_update;
    string m_insertInto;
    string m_createTable;
    string m_dropTable;
    string m_alterTable;
    string m_renameTable;
    string m_addColumn;
    string m_join;
    bool m_delete;
    bool m_asc;
    bool m_desc;
    bool m_selectAll;
    int m_queryType;
    bool m_distinct;
    bool m_ifExists;
    bool m_ifNotExists;
    bool m_temporary;

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
    void processAlterClause();

    void insertFromListWithSeparator(vector<string>& whichlist, string separator);
};

#endif /* SRC_DATABASEQUERYBUILDER_H_ */
