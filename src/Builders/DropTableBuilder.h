/*
 * DropTable.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_DROPTABLEBUILDER_H_
#define SRC_BUILDERS_DROPTABLEBUILDER_H_

#include "QueryBuilder.h"

class DropTableBuilder : public QueryBuilder
{
private:

    std::string m_dropTable;
    bool m_ifExists;

public:

    DropTableBuilder();
    ~DropTableBuilder();

    DropTableBuilder& Drop(const std::string& table);
    DropTableBuilder& IfExists();
    std::string Build();

};



#endif /* SRC_BUILDERS_DROPTABLEBUILDER_H_ */
