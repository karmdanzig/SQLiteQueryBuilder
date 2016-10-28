/*
 * GroupBy.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "GroupBy.h"

GroupBy::GroupBy(const std::vector<std::string>& groupByList)
: groupByList(groupByList)
{
    processKeyword();
}

GroupBy::~GroupBy()
{
}

void GroupBy::processKeyword()
{
    if (!groupByList.empty())
    {
        addReturnLine();
        m_completeKeyword.append(GroupByClause + " ");
        insertFromListWithSeparator(groupByList, ", ");
    }

}


