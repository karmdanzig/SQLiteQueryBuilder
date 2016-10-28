/*
 * GroupBy.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef GROUPBY_H_
#define GROUPBY_H_

#include "Keyword.h"

class GroupBy : public Keyword
{
private:

    std::vector<std::string> groupByList;

public:

    GroupBy(const std::vector<std::string>& groupbyList);

    void processKeyword();
};



#endif /* GROUPBY_H_ */
