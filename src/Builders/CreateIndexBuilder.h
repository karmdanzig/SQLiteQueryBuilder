/*
 * CreateIndex.h
 *
 *  Created on: 1 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_CREATEINDEXBUILDER_H_
#define SRC_BUILDERS_CREATEINDEXBUILDER_H_

#include "QueryBuilder.h"

class CreateIndexBuilder : public QueryBuilder
{
private:

    std::string m_index;
    std::string m_table;
    bool m_unique;
    bool m_ifNotExists;
    std::vector<std::string> m_columnsList;

public:

    CreateIndexBuilder();
    ~CreateIndexBuilder();

    CreateIndexBuilder& CreateIndex(const std::string& index);
    CreateIndexBuilder& CreateUniqueIndex(const std::string& index);
    CreateIndexBuilder& IfNotExists();
    CreateIndexBuilder& OnTable(const std::string& table);
    CreateIndexBuilder& Columns(const std::string& columns);

    std::string Build();

};




#endif /* SRC_BUILDERS_CREATEINDEXBUILDER_H_ */
