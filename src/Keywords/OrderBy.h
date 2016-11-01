/*
 * OrderBy.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_ORDERBY_H_
#define SRC_ORDERBY_H_

#include "Keyword.h"

namespace Keys
{

class OrderBy : public Keyword
{
private:

    std::vector<std::string> orderByList;
    bool ascending;
    bool descending;

public:

    OrderBy(const std::vector<std::string>& orderByList, const bool& ascending, const bool& descending);
    ~OrderBy();
    void processKeyword();
};

}

#endif /* SRC_ORDERBY_H_ */
