/*
 * From.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "From.h"

namespace Keys
{

From::From(const std::string& table)
: table(table)
{
    processKeyword();
}

From::From(const std::string& table, const std::string& join, const std::vector<std::string>& fromList, const std::vector<std::string>& onList, const std::vector<std::string>& operatorList)
: table(table), join(join), fromList(fromList), onList(onList), operatorList(operatorList)
{
    processKeyword();
}

From::~From()
{
}

void From::processKeyword()
{
    addReturnLine();
    m_completeKeyword.append(FromClause + " ");

    if (!table.empty())
    {
        m_completeKeyword.append(table);
        if (!join.empty())
        {
            m_completeKeyword.append(" " + join);
        }
    }

    if (!fromList.empty())
    {
        insertFromListWithSeparator(fromList, " JOIN ");
        m_completeKeyword.append(" " + OnClause + " ");
        insertFromListWithOperatorList(onList, operatorList);
    }
}

}


