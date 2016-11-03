/*
 * CreateBuilder.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_CREATETABLEBUILDER_H_
#define SRC_BUILDERS_CREATETABLEBUILDER_H_

#include "QueryBuilder.h"

class CreateTableBuilder : public QueryBuilder
{
private:

    std::string m_table;
    bool m_temporary;
    bool m_ifNotExists;
    std::vector<std::string> m_fieldsList;

public:

    CreateTableBuilder();
    ~CreateTableBuilder();

    CreateTableBuilder& Create(const std::string& table);
    CreateTableBuilder& Temporary();
    CreateTableBuilder& IfNotExists();
    CreateTableBuilder& Field(const std::string& fieldName,  const std::string& fieldType, const bool& primaryKey, const bool& notNull);

    std::string Build();

};



#endif /* SRC_BUILDERS_CREATETABLEBUILDER_H_ */
