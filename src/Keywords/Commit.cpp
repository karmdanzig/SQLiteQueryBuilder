/*
 * Commit.cpp
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#include "Commit.h"

namespace Keys
{

Commit::Commit()
{
    processKeyword();
}

Commit::~Commit()
{
}

void Commit::processKeyword()
{
    m_completeKeyword = CommitClause;
}

}



