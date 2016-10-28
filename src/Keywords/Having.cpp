/*
 * Having.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Having.h"

namespace Keys
{

Having::Having(const std::vector<std::string>& havingList)
: havingList(havingList)
{
    processKeyword();
}

Having::~Having()
{
}


void Having::processKeyword()
{
    if (!havingList.empty())
    {
        addReturnLine();
        m_completeKeyword.append(HavingClause + " ");
        insertFromListWithSeparator(havingList, ", ");
    }

}

}

