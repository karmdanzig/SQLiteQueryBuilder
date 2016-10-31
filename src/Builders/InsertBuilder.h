/*
 * InsertBuilder.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_INSERTBUILDER_H_
#define SRC_BUILDERS_INSERTBUILDER_H_

#include "QueryBuilder.h"

class InsertBuilder : public QueryBuilder
{
private:

    std::string m_table;
    std::vector<std::string> m_valuesList;

public:

    InsertBuilder();
    ~InsertBuilder();

    InsertBuilder& InsertInto(const std::string& table);
    InsertBuilder& Values(const std::string& value);
    InsertBuilder& Values(const int& value);
    std::string Build();

};



#endif /* SRC_BUILDERS_INSERTBUILDER_H_ */
