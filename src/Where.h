/*
 * Where.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_WHERE_H_
#define SRC_WHERE_H_

#include "Keyword.h"

class Where : public Keyword
{

public:

    Where();

    void processWhereClause(const std::vector<std::string>& whereList);
};



#endif /* SRC_WHERE_H_ */
