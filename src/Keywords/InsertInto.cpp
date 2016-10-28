/*
 * InsertInto.cpp
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#include "InsertInto.h"

InsertInto::InsertInto(const std::string& table)
: table(table)
{
    processKeyword();
}

InsertInto::~InsertInto()
{
}

void InsertInto::processKeyword()
{
    m_completeKeyword = InsertIntoClause + " " + table;
}





