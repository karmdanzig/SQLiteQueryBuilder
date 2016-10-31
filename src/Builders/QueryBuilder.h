/*
 * QueryBuilder.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_QUERYBUILDER_H_
#define SRC_BUILDERS_QUERYBUILDER_H_

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdarg.h>
#include <sstream>
#include "../Constants.h"

class QueryBuilder
{
protected:

    std::string m_fromTable;
    std::vector<std::string> m_havingList;
    std::vector<std::string> m_whereList;
    std::queue<std::string> m_operatorList;
    std::vector<std::string> m_groupbyList;
    std::vector<std::string> m_orderbyList;

public:

    QueryBuilder ();

    virtual ~QueryBuilder ();

    virtual std::string Build() = 0;

    virtual QueryBuilder& From(const std::string& fromTable);

    QueryBuilder& Having(const std::string& filterField, const std::string& value);

    QueryBuilder& Having(const std::string& filterField, const int& value);

    QueryBuilder& WhereEqual(const std::string& filterField, const std::string& value);

    QueryBuilder& WhereLessThan(const std::string& filterField, const std::string& value);

    QueryBuilder& WhereGreaterThan(const std::string& filterField, const std::string& value);

    QueryBuilder& WhereEqualOrLessThan(const std::string& filterField, const std::string& value);

    QueryBuilder& WhereEqualOrGreaterThan(const std::string& filterField, const std::string& value);

    QueryBuilder& WhereEqual(const std::string& filterField, const int& value);

    QueryBuilder& WhereLessThan(const std::string& filterField, const int& value);

    QueryBuilder& WhereGreaterThan(const std::string& filterField, const int& value);

    QueryBuilder& WhereEqualOrLessThan(const std::string& filterField, const int& value);

    QueryBuilder& WhereEqualOrGreaterThan(const std::string& filterField, const int& value);

    QueryBuilder& WhereLike(const std::string& filterField, const std::string& value);

    QueryBuilder& WhereLike(const std::string& filterField, const int& value);

    QueryBuilder& WhereNotLike(const std::string& filterField, const std::string& value);

    QueryBuilder& WhereNotLike(const std::string& filterField, const int& value);

    QueryBuilder& WhereInQuery(const std::string& filterField, const std::string& query);

    QueryBuilder& WhereIn(const std::string& filterField, const int& numberOfArguments, ... );

    QueryBuilder& WhereBetween(const std::string& filterField, const int& min, const int& max);

    QueryBuilder& WhereBetween(const std::string& filterField, const std::string& min, const std::string& max);

    QueryBuilder& WhereNotBetween(const std::string& filterField, const int& min, const int& max);

    QueryBuilder& WhereNotBetween(const std::string& filterField, const std::string& min, const std::string& max);

    QueryBuilder& And();

    QueryBuilder& Or();

    QueryBuilder& GroupBy(const std::string& column);

    QueryBuilder& OrderBy(const std::string& column);

    QueryBuilder& Asc();

    QueryBuilder& Desc();

};



#endif /* SRC_BUILDERS_QUERYBUILDER_H_ */