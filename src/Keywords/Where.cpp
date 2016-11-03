/*
 * Where.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Where.h"

namespace Keys
{

Where::Where(const std::vector<std::string>& whereList)
: whereList(whereList)
{
    processKeyword();
}

Where::Where(const std::vector<std::string>& whereList, const std::vector<std::string>& operatorList)
: whereList(whereList), operatorList(operatorList)
{
    processKeyword();
}

Where::~Where()
{
}

void Where::processKeyword()
{
    if (!whereList.empty())
    {
        addReturnLine();
        m_completeKeyword.append(WhereClause + " ");
        insertFromListWithOperatorList(whereList, operatorList);
    }

}

}
