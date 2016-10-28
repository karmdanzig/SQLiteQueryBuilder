/*
 * Create.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Create.h"

Create::Create(const std::string& table, const bool& temporary, const bool& ifNotExists)
: table(table), temporary(0), ifNotExists(0)
{
    processKeyword();
}

Create::~Create()
{
}

void Create::processKeyword()
{
    m_completeKeyword = CreateClause + " " + (temporary? TemporaryClause + " " : "") + Table + " " + (ifNotExists? IfNotExistsClause + " " : "") + table;
}


