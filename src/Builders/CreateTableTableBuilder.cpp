/*
 * CreateBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "../Keywords/CreateTableTable.h"
#include "CreateTableBuilder.h"

CreateTableBuilder::CreateTableBuilder() : m_temporary(false), m_ifNotExists(false)
{
}

CreateTableBuilder::~CreateTableBuilder()
{
}

CreateTableBuilder& CreateTableBuilder::Create(const std::string& table)
{
    m_table = table;
    return *this;
}

CreateTableBuilder& CreateTableBuilder::Temporary()
{
    m_temporary = true;
    return *this;
}

CreateTableBuilder& CreateTableBuilder::IfNotExists()
{
    m_ifNotExists = true;
    return *this;
}

CreateTableBuilder& CreateTableBuilder::Field(const std::string& fieldName,  const std::string& fieldType, const bool& primaryKey, const bool& notNull)
{
    m_fieldsList.push_back(fieldName + " " + fieldType + " " + (primaryKey? PrimaryKeyClause + " " : "") + (notNull? NotNullClause : ""));
    return *this;
}

std::string CreateTableBuilder::Build()
{
    Keys::CreateTable t1(m_table, m_temporary, m_ifNotExists, m_fieldsList);
    return t1.getCompleteKeyword() + TerminationQueryCharacter;
}
