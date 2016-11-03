/*
 * RollbackTransactionBuilder.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#include "RollbackTransactionBuilder.h"
#include "../Keywords/Rollback.h"

RollbackTransactionBuilder::RollbackTransactionBuilder()
{
}

RollbackTransactionBuilder::~RollbackTransactionBuilder()
{
}

RollbackTransactionBuilder& RollbackTransactionBuilder::Rollback()
{
    return *this;
}

std::string RollbackTransactionBuilder::Build()
{
    Keys::Rollback t1;
    return t1.getCompleteKeyword() + TerminationQueryCharacter;
}


