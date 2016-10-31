/*
 * UpdateBuilder.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_UPDATEBUILDER_H_
#define SRC_BUILDERS_UPDATEBUILDER_H_

#include "QueryBuilder.h"


class UpdateBuilder : public QueryBuilder
{
private:

    std::string m_table;
    std::vector<std::string> m_setList;

public:

    UpdateBuilder();
    ~UpdateBuilder();

    UpdateBuilder& Update(const std::string& table);
    UpdateBuilder& Set(const std::string& setField, const std::string& value);
    UpdateBuilder& Set(const std::string& setField, const int& value);
    std::string Build();

};



#endif /* SRC_BUILDERS_UPDATEBUILDER_H_ */
