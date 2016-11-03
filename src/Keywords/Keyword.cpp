/*
 * Keyword.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Keyword.h"

namespace Keys
{

Keyword::Keyword() : m_completeKeyword("")
{
}

Keyword::~Keyword()
{
}

void Keyword::insertFromListWithSeparator(const std::vector<std::string>& whichList, const std::string& separator)
{
    for(std::vector<std::string>::const_iterator it = whichList.begin() ; it != whichList.end(); ++it)
    {
        m_completeKeyword.append(*it);
        if (*it != whichList.at(whichList.size() - 1))
        {
            m_completeKeyword.append(separator);
        }

    }
}

void Keyword::insertFromListWithOperatorList(const std::vector<std::string>& whichList, const std::vector<std::string>& operatorList)
{

    for(std::vector<std::string>::const_iterator it = whichList.begin(), it2 = operatorList.begin(); it != whichList.end(); ++it, ++it2)
    {
        m_completeKeyword.append(*it);
        if (*it != whichList.at(whichList.size() - 1))
        {
            m_completeKeyword.append(" " + *it2 +" ");
        }

    }
}

void Keyword::addReturnLine()
{
    m_completeKeyword.append("\n");
}

string& Keyword::getCompleteKeyword()
{
    return m_completeKeyword;
}

}
