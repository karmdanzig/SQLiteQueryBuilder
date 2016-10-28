/*
 * Set.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Set.h"

Set::Set(const std::vector<std::string>& setList)
: setList(setList)
{
    processKeyword();
}

Set::~Set()
{
}

void Set::processKeyword()
{
    m_completeKeyword.append(SetClause + " ");
    insertFromListWithSeparator(setList, ", ");
}
