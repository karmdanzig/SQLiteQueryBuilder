/*
 * SelectBuilder.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "SelectBuilder.h"
#include "../Keywords/Select.h"
#include "../Keywords/From.h"

SelectBuilder::SelectBuilder() : m_selectAll(false), m_fromTable("")
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

SelectBuilder& SelectBuilder::From(const std::string& fromTable)
{
    m_fromTable = fromTable;
    return *this;
}

std::string SelectBuilder::Build()
{
    Keys::Select t(m_selectList, false, false);
    Keys::From t1(m_fromTable);
    return t.getCompleteKeyword() + t1.getCompleteKeyword();
}
