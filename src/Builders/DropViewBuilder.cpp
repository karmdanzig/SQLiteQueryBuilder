/*
 * DropViewBuilder.cpp
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#include "DropViewBuilder.h"
#include "../Keywords/Drop.h"

DropViewBuilder::DropViewBuilder()
: m_ifExists(false)
{
}

DropViewBuilder::~DropViewBuilder()
{
}

DropViewBuilder& DropViewBuilder::DropView(const std::string& nameOfView)
{
    m_nameOfView = nameOfView;
    return *this;
}

DropViewBuilder& DropViewBuilder::IfExists()
{
    m_ifExists = true;
    return *this;
}

std::string DropViewBuilder::Build()
{
    Keys::Drop d(m_nameOfView, m_ifExists, View_DropType);
    return d.getCompleteKeyword() + TerminationQueryCharacter;
}



