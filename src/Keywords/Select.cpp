/*
 * Select.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Select.h"

Select::Select(const std::vector<std::string>& selectList, bool selectAll, bool distinct)
: selectList(selectList), selectAll(0), distinct(0)
{
    processKeyword();
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
