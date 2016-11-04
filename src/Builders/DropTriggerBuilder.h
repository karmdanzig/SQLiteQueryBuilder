/*
 * DropTriggerBuiler.h
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_DROPTRIGGERBUILDER_H_
#define SRC_BUILDERS_DROPTRIGGERBUILDER_H_

#include "QueryBuilder.h"

class DropTriggerBuilder : public QueryBuilder
{
private:

    std::string m_nameOfTrigger;
    bool m_ifExists;

public:

    DropTriggerBuilder();
    ~DropTriggerBuilder();

    DropTriggerBuilder& DropTrigger(const std::string& nameOfTrigger);
    DropTriggerBuilder& IfExists();
    std::string Build();

};



#endif /* SRC_BUILDERS_DROPTRIGGERBUILDER_H_ */
