/*
 * OrderBy.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "OrderBy.h"

namespace Keys
{

OrderBy::OrderBy(const std::vector<std::string>& orderByList)
: orderByList(orderByList)
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

}

}
