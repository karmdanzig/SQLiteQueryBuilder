/*
 * Values.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Values.h"

namespace Keys
{

Values::Values(const std::vector<std::string>& valuesList)
: valuesList(valuesList)
{
    processKeyword();
}

Values::~Values()
{
}

void Values::processKeyword()
{
    m_completeKeyword.append(ValuesClause + " (");
    insertFromListWithSeparator(valuesList, ", ");
    m_completeKeyword.append(")");
}

}
