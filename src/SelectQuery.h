/*
 * SelectQuery.h
 *
 *  Created on: 26 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_SELECTQUERY_H_
#define SRC_SELECTQUERY_H_

#include "Query.h"
#include <vector>
#include <string>

class SelectQuery : public Query
{
    std::string selectClause;
    std::vector<std::string> selectFields;
    std::string trim(std::string& str);
    void stringSeparator(std::string input);
    void addField(std::string newField);
    SelectQuery& Build();

public:

    SelectQuery(std::string selectClause);

};



#endif /* SRC_SELECTQUERY_H_ */
