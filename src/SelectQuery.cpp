/*
 * SelectQuery.cpp
 *
 *  Created on: 26 Oct 2016
 *      Author: porcellic
 */

#include "SelectQuery.h"

SelectQuery& SelectQuery::Build()
{
    return *this;
}


SelectQuery::SelectQuery(std::string selectClause)
{
}

std::string SelectQuery::trim(std::string& str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ')+1);
	return str;
}

void SelectQuery::stringSeparator(std::string input)
{
    std::string temp = "";
    for(int i = 0; i < input.size(); ++i)
    {
        if(input.at(i) != ',')
        {
            temp += input.at(i);
        }
        else
        {
            addField(trim(temp));
            temp = "";
        }

        if(i == input.size() - 1)
        {
            addField(trim(temp));
        }

    }
}

void SelectQuery::addField(std::string newField)
{
    selectFields.push_back(newField);
}
