/*
 * EndTransactionBuilder.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#include "EndTransactionBuilder.h"
#include "../Keywords/End.h"

EndTransactionBuilder::EndTransactionBuilder()
{
}

EndTransactionBuilder::~EndTransactionBuilder()
{
}

EndTransactionBuilder& EndTransactionBuilder::End(const std::string& transaction)
{
    m_transaction = transaction;
    return *this;
}

std::string EndTransactionBuilder::Build()
{
    Keys::End t1(m_transaction);
    return t1.getCompleteKeyword() + TerminationQueryCharacter;
}


