/*
 * Values.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Values.h"

Values::Values(const std::vector<std::string>& valuesList)
: valuesList(valuesList)
{
    processValuesClause();
}

void Values::processValuesClause()
{
    m_completeKeyword.append(ValuesClause + " (");
    insertFromListWithSeparator(valuesList, ", ");
    m_completeKeyword.append(")");
}
