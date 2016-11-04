/*
 * DropViewBuilder.h
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_DROPVIEWBUILDER_H_
#define SRC_BUILDERS_DROPVIEWBUILDER_H_

#include "QueryBuilder.h"

class DropViewBuilder : public QueryBuilder
{
private:

    std::string m_nameOfView;
    bool m_ifExists;

public:

    DropViewBuilder();
    ~DropViewBuilder();

    DropViewBuilder& DropView(const std::string& nameOfView);
    DropViewBuilder& IfExists();
    std::string Build();

};



#endif /* SRC_BUILDERS_DROPVIEWBUILDER_H_ */
