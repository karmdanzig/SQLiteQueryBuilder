/*
 * CreateBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "CreateBuilder.h"
#include "../Keywords/Create.h"

CreateBuilder::CreateBuilder() : m_temporary(false), m_ifNotExists(false)
{
}

CreateBuilder::~CreateBuilder()
{
}

CreateBuilder& CreateBuilder::Create(const std::string& table)
{
    m_table = table;
    return *this;
}

CreateBuilder& CreateBuilder::Temporary()
{
    m_temporary = true;
    return *this;
}

CreateBuilder& CreateBuilder::IfNotExists()
{
    m_ifNotExists = true;
    return *this;
}

CreateBuilder& CreateBuilder::Field(const std::string& fieldName,  const std::string& fieldType, const bool& primaryKey, const bool& notNull)
{
    m_fieldsList.push_back(fieldName + " " + fieldType + " " + (primaryKey? PrimaryKeyClause + " " : "") + (notNull? NotNullClause : ""));
    return *this;
}

std::string CreateBuilder::Build()
{
    Keys::Create t1(m_table, m_temporary, m_ifNotExists, m_fieldsList);
    return t1.getCompleteKeyword() + TerminationQueryCharacter;
}
