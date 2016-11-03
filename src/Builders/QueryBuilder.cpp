/*
 * QueryBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "QueryBuilder.h"

QueryBuilder::QueryBuilder() : m_fromTable(""), m_ascending(false), m_descending(false)
{
}

QueryBuilder::~QueryBuilder()
{
}

QueryBuilder& QueryBuilder::From(const std::string& fromTable)
{
    m_fromTable = fromTable;
    return *this;
}

QueryBuilder& QueryBuilder::Having(const std::string& filterField, const std::string& value)
{
    m_havingList.push_back(filterField + " = \'" + value + "\'");
    return *this;
}

QueryBuilder& QueryBuilder::Having(const std::string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_havingList.push_back(filterField + " = " + ss.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereInQuery(const std::string& filterField, const std::string& value)
{
    std::string temp1 = value;
    size_t start_pos = temp1.find(TerminationQueryCharacter);
    if(start_pos != std::string::npos)
    {
        temp1.replace(start_pos, TerminationQueryCharacter.length(), "");
    }
    temp1 = filterField + " " + InClause + " (" + temp1 + ")";
    m_whereList.push_back(temp1);
    return *this;
}

QueryBuilder& QueryBuilder::WhereIn(const std::string& filterField, const int& numberOfArguments, ... )
{
    std::string temp = filterField + " " + InClause + " (";
    va_list arguments;
    va_start (arguments, numberOfArguments);
    ostringstream ss;
    for (int x = 0; x < numberOfArguments; x++)
    {
        int value = va_arg (arguments, int);
        x == numberOfArguments-1 ? (ss << value) : (ss << value << ",");
    }

    va_end (arguments);

    temp.append(ss.str()+")");
    m_whereList.push_back(temp);
    return *this;
}

QueryBuilder& QueryBuilder::WhereBetween(const std::string& filterField, const int& min, const int& max)
{
    ostringstream ss, ss1;
    ss << min;
    ss1 << max;
    m_whereList.push_back(filterField + " " + BetweenClause + " " + ss.str() + " " + AndClause + " " + ss1.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereBetween(const std::string& filterField, const std::string& min, const std::string& max)
{
    m_whereList.push_back(filterField + " " + BetweenClause + " " + min + " " + AndClause + " " + max);
    return *this;
}

QueryBuilder& QueryBuilder::WhereNotBetween(const std::string& filterField, const int& min, const int& max)
{
    ostringstream ss, ss1;
    ss << min;
    ss1 << max;
    m_whereList.push_back(filterField + " " + NotClause + " " + BetweenClause + " " + ss.str() + " " + AndClause + " " + ss1.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereNotBetween(const std::string& filterField, const std::string& min, const std::string& max)
{
    m_whereList.push_back(filterField + " " + NotClause + " " + BetweenClause + " " + min + " " + AndClause + " " + max);
    return *this;
}

QueryBuilder& QueryBuilder::WhereEqual(const std::string& filterField, const std::string& value)
{
    m_whereList.push_back(filterField + " " + EqualClause + " \'" + value + "\'");
    return *this;
}

QueryBuilder& QueryBuilder::WhereLessThan(const std::string& filterField, const std::string& value)
{
    m_whereList.push_back(filterField + " " + LessClause + " \'" + value + "\'");
    return *this;
}

QueryBuilder& QueryBuilder::WhereGreaterThan(const std::string& filterField, const std::string& value)
{
    m_whereList.push_back(filterField + " " + GreaterClause + " \'" + value + "\'");
    return *this;
}

QueryBuilder& QueryBuilder::WhereEqualOrLessThan(const std::string& filterField, const std::string& value)
{
    m_whereList.push_back(filterField + " " + LessOrEqualClause + " \'" + value + "\'");
    return *this;
}

QueryBuilder& QueryBuilder::WhereEqualOrGreaterThan(const std::string& filterField, const std::string& value)
{
    m_whereList.push_back(filterField + " " + GreaterOrEqualClause + " \'" + value + "\'");
    return *this;
}

QueryBuilder& QueryBuilder::WhereEqual(const std::string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + EqualClause + " " + ss.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereLessThan(const std::string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + LessClause + " " + ss.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereGreaterThan(const std::string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + GreaterClause + " " + ss.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereEqualOrLessThan(const std::string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + LessOrEqualClause + " " + ss.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereEqualOrGreaterThan(const std::string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + GreaterOrEqualClause + " " + ss.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereLike(const std::string& filterField, const std::string& value)
{
    m_whereList.push_back(filterField + " " + LikeClause + " \'" + value + "\'");
    return *this;
}

QueryBuilder& QueryBuilder::WhereLike(const std::string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + LikeClause + " " + ss.str());
    return *this;
}

QueryBuilder& QueryBuilder::WhereNotLike(const std::string& filterField, const std::string& value)
{
    m_whereList.push_back(filterField + " " + NotClause + " " + LikeClause + " \'" + value + "\'");
    return *this;
}

QueryBuilder& QueryBuilder::WhereNotLike(const std::string& filterField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_whereList.push_back(filterField + " " + NotClause + " " + LikeClause + " " + ss.str());
    return *this;
}


QueryBuilder& QueryBuilder::And()
{
    m_operatorList.push_back(AndClause);
    return *this;
}

QueryBuilder& QueryBuilder::Or()
{
    m_operatorList.push_back(OrClause);
    return *this;
}

QueryBuilder& QueryBuilder::GroupBy(const std::string& column)
{
    m_groupbyList.push_back(column);
    return *this;
}

QueryBuilder& QueryBuilder::OrderBy(const std::string& column)
{
    m_orderbyList.push_back(column);
    return *this;
}

QueryBuilder& QueryBuilder::Asc()
{
    m_ascending = true;
    return *this;
}

QueryBuilder& QueryBuilder::Desc()
{
    m_descending = true;
    return *this;
}

QueryBuilder& QueryBuilder::FromAs(const std::string& table, const std::string& alias)
{
    m_fromAsList.push_back(table + " " + AsClause + " " + alias);
    return *this;
}

QueryBuilder& QueryBuilder::JoinAs(const std::string& table, const std::string& alias)
{
    m_fromAsList.push_back(table + " " + AsClause + " " + alias);
    return *this;
}

QueryBuilder& QueryBuilder::OnEqual(const std::string& column, const std::string& alias1, const std::string& alias2)
{
    m_onList.push_back(alias1 + "." + column +  " = " + alias2 + "." + column);
    return *this;
}

QueryBuilder& QueryBuilder::NaturalJoin(const std::string& table)
{
    m_join = NaturalClause + " "  + JoinClause + " " + table;
    return *this;
}

QueryBuilder& QueryBuilder::CrossJoin(const std::string& table)
{
    m_join = CrossClause + " " + JoinClause + " " + table;
    return *this;
}

QueryBuilder& QueryBuilder::NaturalLeftOuterJoin(const std::string& table)
{
    m_join = NaturalClause + " " + LeftClause + " " + OuterClause + " " + JoinClause + " " + table;
    return *this;
}
