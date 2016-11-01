/*
 * DeleteBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "DeleteBuilder.h"
#include "../Keywords/From.h"
#include "../Keywords/Where.h"

DeleteBuilder::DeleteBuilder()
{
}

DeleteBuilder::~DeleteBuilder()
{
}

DeleteBuilder& DeleteBuilder::Delete()
{
    return *this;
}

std::string DeleteBuilder::Build()
{
    std::string returnstring = "DELETE";
    Keys::From t1(m_fromTable);
    Keys::Where w(m_whereList);
    return returnstring + t1.getCompleteKeyword() + w.getCompleteKeyword() +";";
}


