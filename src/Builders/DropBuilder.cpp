/*
 * DropBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "DropBuilder.h"
#include "../Keywords/Drop.h"

DropBuilder::DropBuilder() : m_ifExists(false)
{
}

DropBuilder::~DropBuilder()
{
}

DropBuilder& DropBuilder::Drop(const std::string& table)
{
    m_dropTable = table;
    return *this;
}

DropBuilder& DropBuilder::IfExists()
{
    m_ifExists = true;
    return *this;
}

std::string DropBuilder::Build()
{
    Keys::Drop d(m_dropTable, m_ifExists);
    return d.getCompleteKeyword() + ";";
}


