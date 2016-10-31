/*
 * InsertBuilder.cpp
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#include "InsertBuilder.h"
#include "../Keywords/InsertInto.h"
#include "../Keywords/Values.h"

InsertBuilder::InsertBuilder()
{
}

InsertBuilder::~InsertBuilder()
{
}

InsertBuilder& InsertBuilder::InsertInto(const std::string& table)
{
    m_table = table;
    return *this;
}

InsertBuilder& InsertBuilder::Values(const std::string& value)
{
    m_valuesList.push_back("\'" + value + "\'");
    return *this;
}

InsertBuilder& InsertBuilder::Values(const int& value)
{
    ostringstream ss;
    ss << value;
    m_valuesList.push_back(ss.str());
    return *this;
}

std::string InsertBuilder::Build()
{
    Keys::InsertInto d(m_table);
    Keys::Values t(m_valuesList);
    return d.getCompleteKeyword() + "\n" + t.getCompleteKeyword();
}


