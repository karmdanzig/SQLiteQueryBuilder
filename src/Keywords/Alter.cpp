/*
 * Alter.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Alter.h"

namespace Keys
{

Alter::Alter(const std::string& table, const AlterType& type, const std::string& newvalue)
: table(table), type(type), newvalue(newvalue)
{
    processKeyword();
}

Alter::~Alter()
{
}

void Alter::processKeyword()
{
    m_completeKeyword = AlterClause + " " + table + " ";
    if (type == RenameTo)
    {
        m_completeKeyword.append(RenameToClause + " " + newvalue);
    }
    else if (type == AddColumn)
    {
        m_completeKeyword.append(AddColumnClause + " " + newvalue);
    }
}

}
