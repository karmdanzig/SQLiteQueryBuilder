/*
 * Rollback.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */


#include "Rollback.h"

namespace Keys
{

Rollback::Rollback()
{
    processKeyword();
}

Rollback::~Rollback()
{
}

void Rollback::processKeyword()
{
    m_completeKeyword = RollbackClause;
}

}

