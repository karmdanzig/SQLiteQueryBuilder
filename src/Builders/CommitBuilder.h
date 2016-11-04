/*
 * CommitBuilder.h
 *
 *  Created on: 4 Nov 2016
 *      Author: porcellic
 */

#ifndef SRC_BUILDERS_COMMITBUILDER_H_
#define SRC_BUILDERS_COMMITBUILDER_H_

#include "QueryBuilder.h"

class CommitBuilder : public QueryBuilder
{
public:

    CommitBuilder();
    ~CommitBuilder();

    CommitBuilder& Commit();
    std::string Build();

};



#endif /* SRC_BUILDERS_COMMITBUILDER_H_ */
