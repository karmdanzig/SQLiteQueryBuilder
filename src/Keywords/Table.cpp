/*
 * Table.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Table.h"

namespace Keys
{

Table::Table(const std::vector<std::string>& fieldsList)
: fieldsList(fieldsList)
{
    processKeyword();
}

Table::~Table()
{
}

void Table::processKeyword()
{
    m_completeKeyword.append(" (");
    addReturnLine();
    insertFromListWithSeparator(fieldsList, ",\n");
    m_completeKeyword.append(")");
}

}

