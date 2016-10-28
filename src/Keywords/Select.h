/*
 * Select.h
 *
 *  Created on: 28 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_KEYWORDS_SELECT_H_
#define SRC_KEYWORDS_SELECT_H_

#include "Keyword.h"

class Select : public Keyword
{
private:

    std::vector<std::string> selectList;
    bool distinct;
    bool selectAll;

public:

    Select(const std::vector<std::string>& selectList, bool selectAll, bool distinct);

    void processSelectClause();
};



#endif /* SRC_KEYWORDS_SELECT_H_ */
