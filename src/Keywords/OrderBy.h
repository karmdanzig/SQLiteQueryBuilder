/*
 * OrderBy.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_ORDERBY_H_
#define SRC_ORDERBY_H_

#include "Keyword.h"

class OrderBy : public Keyword
{
private:

    std::vector<std::string> orderByList;

public:

    OrderBy(const std::vector<std::string>& orderByList);

    void processOrderByClause();
};



#endif /* SRC_ORDERBY_H_ */
