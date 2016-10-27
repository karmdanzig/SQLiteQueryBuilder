/*
 * Where.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Where.h"

Where::Where()
{
}


std::string Where::processWhereClause(const std::vector<std::string>& whereList)
{
    std::string returnString = "";
    std::queue<std::string> theQueue;

    if (!whereList.empty())
    {
        addReturnLine();
        returnString.append(WhereClause + " ");
        insertFromListWithOperatorList(whereList, theQueue);
    }

    return returnString;
}
