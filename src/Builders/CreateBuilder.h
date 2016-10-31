/*
 * CreateBuilder.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_CREATEBUILDER_H_
#define SRC_BUILDERS_CREATEBUILDER_H_

#include "QueryBuilder.h"

class CreateBuilder : public QueryBuilder
{
private:

    std::string m_table;
    bool m_temporary;
    bool m_ifNotExists;
    std::vector<std::string> m_fieldsList;

public:

    CreateBuilder();
    ~CreateBuilder();

    CreateBuilder& Create(const std::string& table);
    CreateBuilder& Temporary();
    CreateBuilder& IfNotExists();
    CreateBuilder& Field(const std::string& fieldName,  const std::string& fieldType, const bool& primaryKey, const bool& notNull);

    std::string Build();

};



#endif /* SRC_BUILDERS_CREATEBUILDER_H_ */
