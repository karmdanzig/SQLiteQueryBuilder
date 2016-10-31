/*
 * DeleteBuilder.h
 *
 *  Created on: 31 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_DELETEBUILDER_H_
#define SRC_BUILDERS_DELETEBUILDER_H_

#include "QueryBuilder.h"

class DeleteBuilder : public QueryBuilder
{

public:

    DeleteBuilder();
    ~DeleteBuilder();

    DeleteBuilder& Delete();
    std::string Build();

};



#endif /* SRC_BUILDERS_DELETEBUILDER_H_ */
