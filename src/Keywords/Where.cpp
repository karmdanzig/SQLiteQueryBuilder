/*
 * Where.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Where.h"

Where::Where(const std::vector<std::string>& whereList, std::queue<std::string>& theQueue)
: whereList(whereList), theQueue(theQueue)
{
    processWhereClause();
}


void Where::processWhereClause()
{
    if (!whereList.empty())
    {
        addReturnLine();
        m_completeKeyword.append(WhereClause + " ");
        insertFromListWithOperatorList(whereList, theQueue);
    }

}
