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
    Keys::Select t(m_selectList, false, false);
    Keys::From f(m_fromTable);
    Keys::Where w(m_whereList);
    return t.getCompleteKeyword() + f.getCompleteKeyword() + w.getCompleteKeyword();
}
