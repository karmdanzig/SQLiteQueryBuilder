/*
 * From.cpp
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#include "From.h"

From::From(std::string table) : table(table)
{
    processKeyword();
}


void From::processKeyword()
{


    if (!table.empty())
    {
        addReturnLine();
        m_completeKeyword.append(FromClause + " " + table);
        /*if (!m_join.empty())
        {
            m_completeKeyword.append(" " + m_join);
        }*/
    }

    /*if (!m_fromAsList.empty())
    {
        insertFromListWithSeparator(whereList, " JOIN ");
        m_completeKeyword.append(" " + OnClause + " ");
        insertFromListWithOperatorList(m_OnList);
    }*/
};


