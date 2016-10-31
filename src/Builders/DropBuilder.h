/*
 * DropTable.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_DROPBUILDER_H_
#define SRC_BUILDERS_DROPBUILDER_H_

#include "QueryBuilder.h"

class DropBuilder : public QueryBuilder
{
private:

    std::string m_dropTable;
    bool m_ifExists;

public:

    DropBuilder();
    ~DropBuilder();

    DropBuilder& Drop(const std::string& table);
    DropBuilder& IfExists();
    std::string Build();

};



#endif /* SRC_BUILDERS_DROPBUILDER_H_ */
