/*
 * Drop.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "Drop.h"

namespace Keys
{

Drop::Drop(const std::string& table, const bool& ifExists, DropType typeOfDropOrCreate)
: table(table), ifExists(ifExists), typeOfDropOrCreate(typeOfDropOrCreate)
{
    processKeyword();
}

Drop::~Drop()
{
}

void Drop::processKeyword()
{
    m_completeKeyword = DropClause + " " + returnTypeOfDropOrCreate(typeOfDropOrCreate) + " " + (ifExists? IfExistsClause + " " : "") + table;
}

}
