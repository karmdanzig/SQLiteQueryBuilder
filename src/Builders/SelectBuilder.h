/*
 * SelectBuilder.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_SELECTBUILDER_H_
#define SRC_BUILDERS_SELECTBUILDER_H_

#include "../DataBaseQueryBuilder.h"

class SelectBuilder : public DataBaseQueryBuilder
{

    std::vector<std::string> m_selectList;
    bool m_selectAll;
    std::string m_fromTable;

public:

    SelectBuilder();
    ~SelectBuilder();

    SelectBuilder& Select(const std::string& columnToSelect);
    SelectBuilder& SelectAll();
    SelectBuilder& From(const std::string& fromTable);

    std::string Build();

};



#endif /* SRC_BUILDERS_SELECTBUILDER_H_ */
