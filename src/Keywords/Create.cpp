/*
 * Create.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Create.h"

namespace Keys
{

Create::Create(const std::string& table, const bool& temporary, const bool& ifNotExists, std::vector<std::string>& fieldsList)
: table(table), temporary(false), ifNotExists(false), fieldsList(fieldsList)
{
    processKeyword();
}

Create::~Create()
{
}

void Create::processKeyword()
{
    m_completeKeyword = CreateClause + " " + (temporary? TemporaryClause + " " : "") + Table + " " + (ifNotExists? IfNotExistsClause + " " : "") + table;
    m_completeKeyword.append(" (");
    addReturnLine();
    insertFromListWithSeparator(fieldsList, ",\n");
    m_completeKeyword.append(")");
}

}

