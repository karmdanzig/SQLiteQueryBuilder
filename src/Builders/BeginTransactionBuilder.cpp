/*
 * BeginTransactionBuilder.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#include "BeginTransactionBuilder.h"
#include "../Keywords/Begin.h"

BeginTransactionBuilder::BeginTransactionBuilder()
{
}

BeginTransactionBuilder::~BeginTransactionBuilder()
{
}

BeginTransactionBuilder& BeginTransactionBuilder::Begin()
{
    return *this;
}

BeginTransactionBuilder& BeginTransactionBuilder::Begin(const std::string& transaction)
{
    m_transaction = transaction;
    return *this;
}

std::string BeginTransactionBuilder::Build()
{
    Keys::Begin t1(m_transaction);
    return t1.getCompleteKeyword();
}


