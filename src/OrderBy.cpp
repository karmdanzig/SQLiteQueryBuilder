/*
 * OrderBy.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "OrderBy.h"

OrderBy::OrderBy(const std::vector<std::string>& orderByList)
: orderByList(orderByList)
{
    processOrderByClause();
}


void OrderBy::processOrderByClause()
{
    if (!orderByList.empty())
    {
        addReturnLine();
        m_completeKeyword.append(OrderByClause + " ");
        insertFromListWithSeparator(orderByList, ", ");
    }

}


