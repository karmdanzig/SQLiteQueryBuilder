/*
 * Begin.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#include "Begin.h"

namespace Keys
{

Begin::Begin()
{
    processKeyword();
}

Begin::Begin(const std::string& transaction) : transaction(transaction)
{
    processKeyword();
}

Begin::~Begin()
{
}

void Begin::processKeyword()
{
    m_completeKeyword = BeginClause + " " + (transaction.empty()? "" : transaction);
}

}


