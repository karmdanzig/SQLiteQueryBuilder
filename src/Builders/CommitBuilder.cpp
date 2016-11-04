/*
 * CommitBuilder.cpp
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#include "CommitBuilder.h"
#include "../Keywords/Commit.h"

CommitBuilder::CommitBuilder()
{
}

CommitBuilder::~CommitBuilder()
{
}

CommitBuilder& CommitBuilder::Commit()
{
    return *this;
}

std::string CommitBuilder::Build()
{
    Keys::Commit t1;
    return t1.getCompleteKeyword() + TerminationQueryCharacter;
}


