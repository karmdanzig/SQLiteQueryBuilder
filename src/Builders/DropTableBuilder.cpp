/*
 * DropBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "../Keywords/Drop.h"
#include "DropTableBuilder.h"

DropTableBuilder::DropTableBuilder()
: m_ifExists(false)
{
}

DropTableBuilder::~DropTableBuilder()
{
}

DropTableBuilder& DropTableBuilder::Drop(const std::string& table)
{
    m_dropTable = table;
    return *this;
}

DropTableBuilder& DropTableBuilder::IfExists()
{
    m_ifExists = true;
    return *this;
}

std::string DropTableBuilder::Build()
{
    Keys::Drop d(m_dropTable, m_ifExists, Table_DropType);
    return d.getCompleteKeyword() + TerminationQueryCharacter;
}


