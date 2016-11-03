/*
 * AlterBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "AlterBuilder.h"

AlterBuilder::AlterBuilder() : m_tableToAlter(""), m_type(::NoneAlterType), m_newValue("")
{
}

AlterBuilder::~AlterBuilder()
{
}

AlterBuilder& AlterBuilder::Alter(const std::string& table)
{
    m_tableToAlter = table;
    return *this;
}

AlterBuilder& AlterBuilder::RenameTo(const std::string& table)
{
    m_type = ::RenameTo;
    m_newValue = table;
    return *this;
}

AlterBuilder& AlterBuilder::AddColumn(const std::string& fieldName, const std::string& fieldType, const bool& primaryKey, const bool& notNull)
{
    m_type = ::AddColumn;
    m_newValue = fieldName + " " + fieldType + " " + (primaryKey? PrimaryKeyClause + " " : "") + (notNull? NotNullClause : "");
    return *this;
}

std::string AlterBuilder::Build()
{
    Keys::Alter t1(m_tableToAlter, m_type, m_newValue);
    return t1.getCompleteKeyword() + TerminationQueryCharacter;
}


