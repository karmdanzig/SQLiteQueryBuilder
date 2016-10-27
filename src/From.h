/*
 * From.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef FROM_H_
#define FROM_H_


#include "Keyword.h"

class From : public Keyword
{

public:

    From();

    void processFromClause(const std::vector<std::string>& whereList);
};



#endif /* FROM_H_ */
