/*
 * Where.h
 *
 *  Created on: 27 Oct 2016
 *      Author: porcellic
 */

#ifndef SRC_WHERE_H_
#define SRC_WHERE_H_

#include "Keyword.h"

namespace Keys
{

class Where : public Keyword
{
private:

    std::vector<std::string> whereList;
    std::vector<std::string> operatorList;

public:

    Where(const std::vector<std::string>& whereList);
    Where(const std::vector<std::string>& whereList, const std::vector<std::string>& operatorList);
    ~Where();
    void processKeyword();
};

}

#endif /* SRC_WHERE_H_ */
