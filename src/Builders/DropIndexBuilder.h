/*
 * DropIndexBuilder.h
 *
 *  Created on: 3 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_DROPINDEXBUILDER_H_
#define SRC_BUILDERS_DROPINDEXBUILDER_H_

#include "QueryBuilder.h"

class DropIndexBuilder : public QueryBuilder
{
private:

    std::string m_nameOfIndex;
    bool m_ifExists;

public:

    DropIndexBuilder();
    ~DropIndexBuilder();

    DropIndexBuilder& DropIndex(const std::string& nameOfIndex);
    DropIndexBuilder& IfExists();
    std::string Build();

};



#endif /* SRC_BUILDERS_DROPINDEXBUILDER_H_ */
