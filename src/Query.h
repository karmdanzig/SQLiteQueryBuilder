/*
 * Query.h
 *
 *  Created on: 26 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_QUERY_H_
#define SRC_QUERY_H_
#include <iostream>

class Query
{
    std::string theQuery;

public:

    Query();
    virtual Query& Build() = 0;
};


#endif /* SRC_QUERY_H_ */
