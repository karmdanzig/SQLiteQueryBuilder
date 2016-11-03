/*
 * CreateIndex.cpp
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#include "CreateIndexBuilder.h"
#include "../Keywords/CreateIndex.h"

CreateIndexBuilder::CreateIndexBuilder() : m_unique(false), m_ifNotExists(false)
{
}

CreateIndexBuilder::~CreateIndexBuilder()
{
}

CreateIndexBuilder& CreateIndexBuilder::CreateIndex(const std::string& index)
{
    m_index = index;
    return *this;
}

CreateIndexBuilder& CreateIndexBuilder::CreateUniqueIndex(const std::string& index)
{
    m_index = index;
    m_unique = true;
    return *this;
}

CreateIndexBuilder& CreateIndexBuilder::IfNotExists()
{
    m_ifNotExists = true;
    return *this;
}

CreateIndexBuilder& CreateIndexBuilder::OnTable(const std::string& table)
{
    m_table = table;
    return *this;
}

CreateIndexBuilder& CreateIndexBuilder::Columns(const std::string& columns)
{
    m_columnsList.push_back(columns);
    return *this;
}

std::string CreateIndexBuilder::Build()
{
    Keys::CreateIndex t1(m_index, m_table, m_unique, m_ifNotExists, m_columnsList);
    return t1.getCompleteKeyword() + TerminationQueryCharacter;
}


