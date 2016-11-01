/*
 * End.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#include "End.h"

namespace Keys
{

End::End(const std::string& transaction) : transaction(transaction)
{
    processKeyword();
}

End::~End()
{
}

void End::processKeyword()
{
    m_completeKeyword = EndClause + " " + transaction;
}

}


