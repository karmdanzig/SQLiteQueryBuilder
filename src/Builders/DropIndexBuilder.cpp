/*
 * DropIndexBuilder.cpp
 *
 *  Created on: 3 Nov 2016
 *      Author: porcellic
 */

#include "DropIndexBuilder.h"
#include "../Keywords/Drop.h"

DropIndexBuilder::DropIndexBuilder()
: m_ifExists(false)
{
}

DropIndexBuilder::~DropIndexBuilder()
{
}

DropIndexBuilder& DropIndexBuilder::DropIndex(const std::string& nameOfIndex)
{
    m_nameOfIndex = nameOfIndex;
    return *this;
}

DropIndexBuilder& DropIndexBuilder::IfExists()
{
    m_ifExists = true;
    return *this;
}

std::string DropIndexBuilder::Build()
{
    Keys::Drop d(m_nameOfIndex, m_ifExists, Index_DropOrCreateType);
    return d.getCompleteKeyword() + TerminationQueryCharacter;
}


