/*
 * OrderBy.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "OrderBy.h"

namespace Keys
{

OrderBy::OrderBy(const std::vector<std::string>& orderByList, const bool& ascending, const bool& descending)
: orderByList(orderByList), ascending(ascending), descending(descending)
{
    processKeyword();
}

OrderBy::~OrderBy()
{
}

void OrderBy::processKeyword()
{
    if (!orderByList.empty())
    {
        addReturnLine();
        m_completeKeyword.append(OrderByClause + " ");
        insertFromListWithSeparator(orderByList, ", ");
    }
    if (ascending)
    {
        m_completeKeyword.append(" " + AscClause);
    }
    if (descending)
    {
        m_completeKeyword.append(" " + DescClause);
    }

}

}
