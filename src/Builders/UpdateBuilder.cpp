/*
 * UpdateBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "UpdateBuilder.h"
#include "../Keywords/Update.h"
#include "../Keywords/Set.h"
#include "../Keywords/Where.h"

UpdateBuilder::UpdateBuilder() : m_table()
{
}

UpdateBuilder::~UpdateBuilder()
{
}

UpdateBuilder& UpdateBuilder::Update(const std::string& table)
{
    m_table = table;
    return *this;
}

UpdateBuilder& UpdateBuilder::Set(const std::string& setField, const std::string& value)
{
    m_setList.push_back(setField + " " + EqualClause + " \'" + value + "\'");
    return *this;
}

UpdateBuilder& UpdateBuilder::Set(const std::string& setField, const int& value)
{
    ostringstream ss;
    ss << value;
    m_setList.push_back(setField + " " + EqualClause + " " + ss.str());
    return *this;
}

std::string UpdateBuilder::Build()
{
    Keys::Update u(m_table);
    Keys::Set s(m_setList);
    Keys::Where w(m_whereList);
    return u.getCompleteKeyword() + s.getCompleteKeyword() + w.getCompleteKeyword();
}
