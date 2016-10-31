/*
 * SelectBuilder.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_SELECTBUILDER_H_
#define SRC_BUILDERS_SELECTBUILDER_H_

#include "QueryBuilder.h"

class SelectBuilder : public QueryBuilder
{

    std::vector<std::string> m_selectList;
    bool m_selectAll;

public:

    SelectBuilder();
    ~SelectBuilder();

    SelectBuilder& Select(const std::string& columnToSelect);
    SelectBuilder& SelectAll();

    std::string Build();

};



#endif /* SRC_BUILDERS_SELECTBUILDER_H_ */
