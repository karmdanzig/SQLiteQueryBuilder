/*
 * SelectBuilder.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "SelectBuilder.h"
#include "../Keywords/Select.h"
#include "../Keywords/From.h"
#include "../Keywords/Where.h"
#include "../Keywords/GroupBy.h"
#include "../Keywords/Having.h"
#include "../Keywords/OrderBy.h"

SelectBuilder::SelectBuilder() : m_selectAll(false), m_distinct(false)
{
}

SelectBuilder::~SelectBuilder()
{
}

SelectBuilder& SelectBuilder::Select(const std::string& columnToSelect)
{
    m_selectList.push_back(columnToSelect);
    return *this;
}

SelectBuilder& SelectBuilder::SelectAll()
{
    m_selectAll = true;
    return *this;
}

SelectBuilder& SelectBuilder::Distinct()
{
    m_distinct = true;
    return *this;
}

std::string SelectBuilder::Build()
{
    Keys::Select t(m_selectList, m_selectAll, m_distinct);
    Keys::From f(m_fromTable, m_join, m_fromAsList, m_onList, m_operatorList);
    Keys::Where w(m_whereList, m_operatorList);
    Keys::GroupBy gb(m_groupbyList);
    Keys::Having h(m_havingList);
    Keys::OrderBy ob(m_orderbyList, m_ascending, m_descending);
    return t.getCompleteKeyword() + f.getCompleteKeyword() + w.getCompleteKeyword() + gb.getCompleteKeyword() + h.getCompleteKeyword() + ob.getCompleteKeyword() +";";
}
