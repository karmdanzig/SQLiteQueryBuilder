/*
 * Keyword.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "Keyword.h"


Keyword::Keyword() : m_completeKeyword("")
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

void Keyword::insertFromListWithOperatorList(const std::vector<std::string>& whichList, std::queue<std::string>& operatorList)
{

    for(std::vector<std::string>::const_iterator it = whichList.begin(); it != whichList.end(); ++it)
    {
        m_completeKeyword.append(*it);
        if (*it != whichList.at(whichList.size() - 1))
        {
            m_completeKeyword.append(" " + operatorList.front() +" ");
            operatorList.pop();
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
