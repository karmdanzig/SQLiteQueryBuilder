/*
 * Select.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Select.h"

namespace Keys
{

Select::Select(const std::vector<std::string>& selectList, const bool& selectAll, const bool& distinct)
: selectList(selectList), selectAll(selectAll), distinct(distinct)
{
    processKeyword();
}

Select::~Select()
{
}

void Select::processKeyword()
{
    m_completeKeyword = SelectClause + " " + (distinct? DistinctClause + " " : "");

    if (selectAll)
    {
        m_completeKeyword.append("*");
    }
    else
    {
        insertFromListWithSeparator(selectList, ",");
    }
}

}
