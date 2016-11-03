/*
 * Create.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "CreateTableTable.h"

namespace Keys
{

CreateTable::CreateTable(const std::string& table, const bool& temporary, const bool& ifNotExists, std::vector<std::string>& fieldsList)
: table(table), temporary(temporary), ifNotExists(ifNotExists), fieldsList(fieldsList)
{
    processKeyword();
}

CreateTable::~CreateTable()
{
}

void CreateTable::processKeyword()
{
    m_completeKeyword = CreateClause + " " + (temporary? TemporaryClause + " " : "") + TableClause + " " + (ifNotExists? IfNotExistsClause + " " : "") + table;
    m_completeKeyword.append(" (");
    addReturnLine();
    insertFromListWithSeparator(fieldsList, ",\n");
    m_completeKeyword.append(")");
}

}

